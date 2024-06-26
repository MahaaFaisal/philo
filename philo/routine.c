/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:28:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/26 13:30:23 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(long milliseconds, t_ph *ph)
{
	long	start;

	start = getmillinow();
	while ((getmillinow() - start) < milliseconds)
	{
		if (should_die(ph) || should_stop(ph->shared))
			return (0);
		usleep(500);
	}
	return (1);
}

void	print_action(t_ph *ph, char *action, char *color)
{
	pthread_mutex_lock(&ph->shared->print_mtx);
	if (should_stop(ph->shared) && !ph->dead)
	{
		pthread_mutex_unlock(&ph->shared->print_mtx);
		return ;
	}
	printf("%s", color);
	printf("%d ", getelapsedtime(ph->shared->start_ms));
	printf("%d ", ph->id + 1);
	printf("%s\n", action);
	printf("%s", NRM);
	pthread_mutex_unlock(&ph->shared->print_mtx);
}

bool	eat(t_ph *ph)
{
	if (should_die(ph) || should_stop(ph->shared))
		return (0);
	pthread_mutex_lock(ph->first_mutex);
	if (should_die(ph) || should_stop(ph->shared)
		|| *(ph->first_fork) == ph->id || ph->first_mutex == ph->sec_mutex)
		return (pthread_mutex_unlock(ph->first_mutex), 0);
	print_action(ph, "has taken a fork", NRM);
	pthread_mutex_lock(ph->sec_mutex);
	if (should_die(ph) || should_stop(ph->shared) || *(ph->sec_fork) == ph->id)
	{
		pthread_mutex_unlock(ph->sec_mutex);
		pthread_mutex_unlock(ph->first_mutex);
		return (0);
	}
	print_action(ph, "has taken a fork ", NRM);
	print_action(ph, "is eating", YEL);
	ph->last_meal = getmillinow();
	ph->meals_num--;
	ft_usleep(ph->shared->tte, ph);
	*(ph->sec_fork) = ph->id;
	pthread_mutex_unlock(ph->sec_mutex);
	*(ph->first_fork) = ph->id;
	pthread_mutex_unlock(ph->first_mutex);
	return (1);
}

void	*eat_think_sleep(void *philo)
{
	t_ph	*ph;

	ph = philo;
	if (ph->id % 2 != 0)
		ft_usleep(ph->shared->tte, ph);
	while (!should_die(ph) && !should_stop(ph->shared))
	{
		eat(ph);
		if (ph->meals_num == 0
			|| (should_die(ph) || should_stop(ph->shared)))
			break ;
		print_action(ph, "is sleeping", BLU);
		if (!ft_usleep(ph->shared->tts, ph))
			break ;
		if (should_die(ph) || should_stop(ph->shared))
			break ;
		print_action(ph, "is thinking", GRN);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:28:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/23 17:26:01 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(long milliseconds, t_ph *ph)
{
	long	start;

	start = getmillinow();
	while ((getmillinow() - start) < milliseconds
		&& !should_die(ph) && !should_stop(ph->shared))
		usleep(500);
	return (0);
}

void	print_action(t_ph *ph, char *action, char *color)
{
	pthread_mutex_lock(&ph->shared->print_mtx);
	printf("%s", color);
	printf("%d ", getelapsedtime(ph->shared->start_ms));
	printf("%d ", ph->id + 1);
	// printf("%d ", getelapsedtime(ph->last_meal));
	printf("%s\n",action);
	printf("%s", NRM);
	pthread_mutex_unlock(&ph->shared->print_mtx);
}

void	eat(t_ph *ph)
{
	if (should_die(ph))
		return ;
	pthread_mutex_lock(ph->first_mutex);
	if (should_die(ph))
	{
		pthread_mutex_unlock(ph->first_mutex);
		return ;
	}
	//check the id for the last fork
	print_action(ph, "has taken a fork", NRM);
	pthread_mutex_lock(ph->sec_mutex);
	//check the id for the last fork
	print_action(ph, "has taken a fork ", NRM);
	print_action(ph, "is eating", YEL);
	ph->last_meal = getmillinow();
	ph->meals_num--;
	ft_usleep(ph->shared->tte, ph);
	pthread_mutex_unlock(ph->sec_mutex);
	pthread_mutex_unlock(ph->first_mutex);
}

void	sleeping(t_ph *ph)
{
	print_action(ph, "is sleeping", BLU);
	ft_usleep(ph->shared->tts, ph);
}

//should the simulation stops immediatel when it eats the meals?
void	*eat_think_sleep(void *philo)
{
	t_ph	*ph;

	ph = philo;
	if (ph->id % 2 == 0)
		usleep(500);
	while (!should_die(ph) && !should_stop(ph->shared))
	{
		eat(ph);
		if (ph->meals_num == 0 ||
			(should_die(ph) || should_stop(ph->shared)))
			break ;
		sleeping(ph);
		if (should_die(ph) || should_stop(ph->shared))
			break ;
		print_action(ph, "is thinking", GRN);
	}
	// if (ph->dead && !should_stop(ph->shared))
	// {
	// 	pthread_mutex_lock(&ph->shared->dead_mtx);
	// 	ph->shared->dead = 1;
	// 	pthread_mutex_unlock(&ph->shared->dead_mtx);
		// print_action(ph, "is dead", RED);
	// }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:28:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/22 11:00:29 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_ph *ph, char *action, char *color)
{
	printf("%s%d %d %s\n%s", color, getelapsedtime(ph->shared->start_ms),
		ph->id, action, NRM);
}

void	eat(t_ph *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_lock(&ph->shared->fork_mtx[ph->id]);
		print_action(ph, "has taken a fork", NRM);
		if (ph->id == 0)
			pthread_mutex_lock(&ph->shared->fork_mtx[ph->shared->ph_num - 1]);
		else
			pthread_mutex_lock(&ph->shared->fork_mtx[ph->id - 1]);
		print_action(ph, "has taken a fork", NRM);
	}
	else
	{
		pthread_mutex_lock(&ph->shared->fork_mtx[ph->id]);
		print_action(ph, "has taken a fork ", NRM);
		pthread_mutex_lock(&ph->shared->fork_mtx[ph->id - 1]);
		print_action(ph, "has taken a fork", NRM);
	}
	print_action(ph, "is eating", YEL);
	usleep(ph->shared->tte * 1000);
	pthread_mutex_unlock(&ph->shared->fork_mtx[ph->id]);
	if (ph->id == 0)
		pthread_mutex_unlock(&ph->shared->fork_mtx[ph->shared->ph_num - 1]);
	else
		pthread_mutex_unlock(&ph->shared->fork_mtx[ph->id - 1]);
}

void	thinking(t_ph *ph)
{
	print_action(ph, "is thinking", GRN);
}

void	sleeping(t_ph *ph)
{
	print_action(ph, "is sleeping", BLU);
	usleep(ph->shared->tts * 1000);
	thinking(ph);
}

void	*eat_think_sleep(void *philo)
{
	t_ph	*ph;

	ph = philo;
	if (ph->id % 2 == 0)
		usleep(50);
	while (!(ph->shared->dead))
	{
		eat(ph);
		sleeping(ph);
	}
	return (0);
}

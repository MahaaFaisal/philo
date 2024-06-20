/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:28:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/20 16:45:27 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_ph *ph, char *action, char *color)
{
	// pthread_mutex_lock(ph->shared->print_mtx);
	printf("%s", color);
	printf("%d ", getelapsedtime(ph->shared->start_ms));
	printf("%d ", ph->id);
	printf("%s\n",action);
	printf("%s", NRM);
	// pthread_mutex_unlock(ph->shared->print_mtx);
}

void	eat(t_ph *ph)
{
	pthread_mutex_lock(ph->first_mutex);
	//check the id for the last fork 
	print_action(ph, "has taken a fork", NRM);
	pthread_mutex_lock(ph->sec_mutex);
	//check the id for the last fork
	print_action(ph, "has taken a fork ", NRM);
	//update the last meal time
	print_action(ph, "is eating", YEL);
	usleep(ph->shared->tte * 1000);
	pthread_mutex_unlock(ph->sec_mutex);
	pthread_mutex_unlock(ph->first_mutex);
}

void	thinking(t_ph *ph)
{
	print_action(ph, "is thinking", GRN);
}

void	sleeping(t_ph *ph)
{
	print_action(ph, "is sleeping", BLU);
	usleep(ph->shared->tts * 1000);
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
		thinking(ph);
	}
	return (0);
}

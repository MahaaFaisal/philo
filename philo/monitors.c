/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:23:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/24 15:44:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	should_die(t_ph *ph)
{
	if (should_stop(ph->shared))
		return (1);
	if (getelapsedtime(ph->last_meal) > ph->shared->ttd)
	{
		ph->dead = 1;
		pthread_mutex_lock(&ph->shared->dead_mtx);
		print_action(ph, "died", RED);
		ph->shared->dead = 1;
		usleep(500);
		pthread_mutex_unlock(&ph->shared->dead_mtx);
		return (1);
	}
	return (0);
}

bool	should_stop(t_shared *shared)
{
	pthread_mutex_lock(&shared->dead_mtx);
	if (shared->dead == 0)
	{
		pthread_mutex_unlock(&shared->dead_mtx);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&shared->dead_mtx);
		return (1);
	}
}

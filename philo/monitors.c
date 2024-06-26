/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:23:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/26 17:16:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	should_die(t_ph *ph)
{
	if (should_stop(ph->shared))
		return (1);
	if (getelapsedtime(ph->last_meal) >= ph->shared->ttd)
	{
		ph->dead = 1;
		pthread_mutex_lock(&ph->shared->dead_mtx);
		ph->shared->stop ++;
		if (ph->shared->stop == 1)
		{
			pthread_mutex_unlock(&ph->shared->dead_mtx);
			print_action(ph, "died", RED);
			return (1);
		}
		else if (ph->shared->stop > 1)
		{
			pthread_mutex_unlock(&ph->shared->dead_mtx);
			return (1);
		}
	}
	return (0);
}

bool	should_stop(t_shared *shared)
{
	pthread_mutex_lock(&shared->dead_mtx);
	if (shared->stop == 0)
	{
		pthread_mutex_unlock(&shared->dead_mtx);
		return (0);
	}
	pthread_mutex_unlock(&shared->dead_mtx);
	return (1);
}

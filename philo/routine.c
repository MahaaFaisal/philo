/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:28:44 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/21 16:32:05 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_ph *ph)
{
	if (ph->id % 2 == 0)
		pthread_mutex_lock(&ph->shared->fork_mtx[ph->id]);
}

void	sleeping(void *ph)
{
	(void)ph ;
}
void	*eat_think_sleep(void *philo)
{
	t_ph	*ph;

	ph = philo;
	if (ph->id % 2 == 0)
		usleep(500);
	while (1)
	{
		
		eat(ph);
	}
}

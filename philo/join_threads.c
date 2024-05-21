/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:36:39 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/21 14:03:00 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_threads(t_shared *shared)
{
	int		i;
	bool	state;

	state = 1;
	i = 0;
	while (i < shared->ph_num)
	{
		if (pthread_join(shared->ph[i].th, NULL))
		{
			write(2, "error in 	thread join\n", 22);
			state = 0;
		}
		if (pthread_mutex_destroy(&shared->fork_mtx[i]))
		{
			write(2, "error in 	mutex destroy\n", 24);
			state = 0;
		}
		i++;
	}
	return (state);
}

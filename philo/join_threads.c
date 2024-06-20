/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:36:39 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/20 16:51:34 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_threads(t_data *data)
{
	int		i;
	bool	state;

	state = 1;
	i = 0;
	while (i < data->ph_num)
	{
		if (pthread_join(data->ph[i].th, NULL))
		{
			write(2, "error in 	thread join\n", 22);
			state = 0;
		}
		if (pthread_mutex_destroy(&data->shared->fork_mtx[i]))
		{
			write(2, "error in 	mutex destroy\n", 24);
			state = 0;
		}
		i++;
	}
	return (state);
}

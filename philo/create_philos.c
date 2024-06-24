/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:20:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/24 08:24:49 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_data *data, int id)
{
	if (id % 2 == 0)
	{
		data->ph[id].first_mutex = &(data->shared->fork_mtx[id]);
		data->ph[id].first_fork = &(data->shared->forks[id]);
		if (id == 0)
		{
			data->ph[id].sec_mutex
				= &(data->shared->fork_mtx[data->ph_num - 1]);
			data->ph[id].sec_fork = &(data->shared->forks[data->ph_num - 1]);
		}
		else
		{
			data->ph[id].sec_mutex = &(data->shared->fork_mtx[id - 1]);
			data->ph[id].sec_fork = &(data->shared->forks[id - 1]);
		}
	}
	else
	{
		data->ph[id].first_mutex = &(data->shared->fork_mtx[id - 1]);
		data->ph[id].first_fork = &(data->shared->forks[id - 1]);
		data->ph[id].sec_mutex = &(data->shared->fork_mtx[id]);
		data->ph[id].sec_fork = &(data->shared->forks[id]);
	}
}

bool	create_philos(t_data *data)
{
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	data->shared->start_ms = getmillitime(start);
	while (i < data->ph_num)
	{
		data->ph[i].dead = 0;
		data->ph[i].id = i;
		data->ph[i].shared = data->shared;
		data->ph[i].meals_num = data->shared->meals_num;
		data->ph[i].last_meal = data->shared->start_ms;
		assign_forks(data, data->ph[i].id);
		if (pthread_create(&data->ph[i].th, NULL,
				&eat_think_sleep, &data->ph[i]))
		{
			write(2, "error in thread creation\n", 25);
			free(data->ph);
			return (0);
		}
		i++;
	}
	return (1);
}

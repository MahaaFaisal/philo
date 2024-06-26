/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:36:39 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/26 12:15:27 by mafaisal         ###   ########.fr       */
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
		i++;
	}
	return (state);
}

bool	destroy_mutexes(t_data *data)
{
	int		i;
	bool	state;

	state = 1;
	i = 0;
	while (data->shared->fork_mtx && i < data->ph_num)
	{
		if (pthread_mutex_destroy(&data->shared->fork_mtx[i]))
		{
			write(2, "error in fork mutex destroy\n", 28);
			state = 0;
		}
		i++;
	}
	pthread_mutex_destroy(&data->shared->print_mtx);
	pthread_mutex_destroy(&data->shared->dead_mtx);
	return (state);
}

void	free_memory(t_data *data)
{
	if (data->shared->fork_mtx)
		free(data->shared->fork_mtx);
	if (data->shared->forks)
		free(data->shared->forks);
	if (data->ph)
		free(data->ph);
	if (data->shared)
		free(data->shared);
}

bool	end_program(t_data *data)
{
	int	state;

	state = 1;
	if (!join_threads(data))
		state = 0;
	if (!destroy_mutexes(data))
		state = 0;
	free_memory(data);
	return (state);
}

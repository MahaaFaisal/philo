/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:36:39 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/25 10:28:00 by mafaisal         ###   ########.fr       */
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
	while (i < data->ph_num)
	{
		if (pthread_mutex_destroy(&data->shared->fork_mtx[i]))
		{
			write(2, "error in fork mutex destroy\n", 28);
			state = 0;
		}
		i++;
	}
	if (pthread_mutex_destroy(&data->shared->print_mtx))
	{
		write(2, "error in 	print mutex destroy\n", 29);
		state = 0;
	}
	if (pthread_mutex_destroy(&data->shared->dead_mtx))
	{
		write(2, "error in dead mutex destroy\n", 28);
		state = 0;
	}
	return (state);
}

void	free_memory(t_data *data)
{
	free(data->shared->fork_mtx);
	free(data->shared->forks);
	free(data->ph);
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

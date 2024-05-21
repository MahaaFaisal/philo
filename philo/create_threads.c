/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:20:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/21 16:28:31 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(t_shared *shared)
{
	int	i;

	shared->ph = malloc((shared->ph_num + 1) * sizeof(t_ph));
	if (!shared->ph)
		return (write(2, "malloc_error\n", 13), 0);
	shared->fork_mtx = malloc((shared->ph_num + 1) * sizeof(pthread_mutex_t));
	if (!shared->fork_mtx)
		return (free(shared->ph), write(2, "malloc_error\n", 13), 0);
	i = 0;
	while (i < shared->ph_num)
	{
		shared->ph[i].id = i;
		shared->ph[i].shared = shared;
		if (pthread_create(&shared->ph[i].th, NULL, &eat_think_sleep, &shared->ph[i]))
		{
			write(2, "error in thread creation\n", 25);
			free(shared->ph);
			return (0);
		}
		if (pthread_mutex_init(&shared->fork_mtx[i], NULL))
		{
			write(2, "error in 	mutex creation\n", 25);
			free(shared->fork_mtx);
			return (0);
		}
		i++;
	}
	return (1);
}

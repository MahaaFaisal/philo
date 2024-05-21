/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:20:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/21 12:43:38 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(t_shared *shared)
{
	int	i;

	shared->th = malloc((shared->ph_num + 1) * sizeof(pthread_t));
	shared->fork_mtx = malloc((shared->ph_num + 1) * sizeof(pthread_mutex_t));
	if (!shared->th)
		return (write(2, "malloc_error\n", 13), 0);
	i = 0;
	while (i < shared->ph_num)
	{
		if (pthread_create(&shared->th[i], NULL, &eat_think_sleep, shared))
		{
			write(2, "error in thread creation\n", 25);
			free(shared->th);
			return (0);
		}
		if (pthread_mutex_init(&shared->fork_mtx[i], NULL))
		{
			write(2, "error in 	mutex creation\n", 25);
			free(shared->fork_mtx);
			return (0);
		}
		else
		{
			printf("mutex created\n");
		}
		i++;
	}
	//? shared->th[shared->ph_num] = NULL;
	//? shared->mtx[shared->ph_num] = NULL;
	return (1);
}

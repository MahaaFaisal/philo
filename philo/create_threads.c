/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:20:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 12:10:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(t_ph *ph)
{
	int	i;

	ph->th = malloc((ph->ph_num + 1) * sizeof(pthread_t));
	ph->fork_mtx = malloc((ph->ph_num + 1) * sizeof(pthread_mutex_t));
	if (!ph->th)
		return (write(2, "malloc_error\n", 13), 0);
	i = 0;
	while (i < ph->ph_num)
	{
		if (pthread_create(&ph->th[i], NULL, &eat_think_sleep, ph))
		{
			write(2, "error in thread creation\n", 25);
			free(ph->th);
			return (0);
		}
		if (pthread_mutex_init(&ph->fork_mtx[i], NULL))
		{
			write(2, "error in 	mutex creation\n", 25);
			free(ph->fork_mtx);
			return (0);
		}
		else
		{
			printf("mutex created\n");
		}
		i++;
	}
	//? ph->th[ph->ph_num] = NULL;
	//? ph->mtx[ph->ph_num] = NULL;
	return (1);
}

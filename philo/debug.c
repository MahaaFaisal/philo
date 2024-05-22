/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:27:21 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/22 10:56:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_shared *shared)
{
	printf("\n------ PHILO INFO -------\n");
	// usleep(4000);
	printf("elapsed time since start : %d\n", getelapsedtime(shared->start_ms));
	usleep(4000);
	printf("elapsed time since start : %d\n", getelapsedtime(shared->start_ms));
	printf("number of philosophers: %d\n", shared->ph_num);
	printf("time to die: %d\n", shared->ttd);
	printf("time to eat: %d\n", shared->tte);
	printf("time to sleep: %d\n", shared->tts);
	printf("number of meals: %d\n", shared->eat_num);

	int	i;

	i = 0;
	while (i < shared->ph_num)
	{
		printf("philosopher number %i id: %d\nlast_meal: %ld\ndead? %p\n",
			i, shared->ph[i].id, shared->ph[i].last_meal, shared->ph[i]->shared->dead);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:36:39 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 11:48:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_threads(t_ph *ph)
{
	int	i;
	bool	state;

	state = 1;
	i = 0;
	while (i < ph->ph_num)
	{
		if (pthread_join(ph->th[i], NULL))
		{
			write(2, "error in 	thread join\n", 25);
			state = 0;
		}
		i++;
	}
	return (state);
}

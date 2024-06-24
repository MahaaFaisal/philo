/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:06 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/24 17:14:49 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (!assign_data(argc, argv, &data))
	{
		free_memory(&data);
		return (1);
	}
	if (!assign_shared(argc, argv, &data))
	{
		destroy_mutexes(&data);
		free_memory(&data);
		return (1);
	}
	if (!create_philos(&data))
	{
		destroy_mutexes(&data);
		free_memory(&data);
		return (1);
	}
	if (!end_program(&data))
		return (1);
	return (0);
}

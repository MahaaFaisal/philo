/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:06 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/20 17:40:40 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (!assign_data(argc, argv, &data))
		return (1);
	if (!assign_shared(argc, argv, &data))
		return (1);
	if (!create_philos(&data))
		return (1);
	printf("threads created\n");
	//monitoring threads here
	if (!join_threads(&data))
		return (1);
	printf("threads joined\n");
}

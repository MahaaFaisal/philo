/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:06 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 11:36:23 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_ph	ph;

	memset(&ph, 0, sizeof(ph));
	if (!assign_values(argc, argv, &ph))
		return (1);
	if (!create_threads(&ph))
		return (1);
	if (!join_threads(&ph))
		return (1);
	print_philo(&ph);
}

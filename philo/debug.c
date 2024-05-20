/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:27:21 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 08:56:49 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_ph *ph)
{
	printf("number of philosophers: %d\n", ph->ph_num);
	printf("time to die: %d\n", ph->ttd);
	printf("time to eat: %d\n", ph->tte);
	printf("time to sleep: %d\n", ph->tts);
	printf("number of meals: %d\n", ph->eat_num);
}

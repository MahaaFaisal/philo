/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:50:09 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 14:48:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	s_to_ms(long second)
{
	return (second * 1000);
}

long	us_to_ms(long microsecond)
{
	return (microsecond / 1000);
}

long	getmillitime(struct timeval time)
{
	return (s_to_ms(time.tv_sec) + us_to_ms(time.tv_usec));
}

int	getelapsedtime(long start_ms)
{
	int				elapsed_time;
	long			now_ms;
	struct timeval	now;

	gettimeofday(&now, NULL);
	now_ms = getmillitime(now);
	elapsed_time = now_ms - start_ms;
	return (elapsed_time);
}

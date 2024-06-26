/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:50:09 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/26 14:55:12 by mafaisal         ###   ########.fr       */
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

long	getmillinow(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (getmillitime(now));
}

int	getelapsedtime(long start_ms)
{
	int				elapsed_time;
	long			now_ms;

	now_ms = getmillinow();
	elapsed_time = now_ms - start_ms;
	return (elapsed_time);
}


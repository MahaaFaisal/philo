/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:24:37 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/26 12:08:28 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	islong(long num, char c, int sign)
{
	if ((sign == -1 && (num > 214748364
				|| (num == 214748364 && (c - '0') > 8)))
		|| (sign == 1 && (num > 214748364
				|| (num == 214748364 && (c - '0') > 7))))
		return (1);
	else
		return (0);
}

int	str_to_int(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		*error = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (islong(result, str[i], sign)
			|| (str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9')))
			return (*error = 1, 0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

bool	assign_data(int argc, char **argv, t_data *data)
{
	int	error;

	error = 0;
	data->ph = 	NULL;
	if (argc < 5 || argc > 6)
		return (write(2, "program takes only 4 or 5 integer values\n", 41), 0);
	data->ph_num = str_to_int(argv[1], &error);
	if (error || data->ph_num <= 0)
		return (write(2, "arguments should be positive integers\n", 38), 0);
	data->ph = malloc((data->ph_num) * sizeof(t_ph));
	if (!data->ph)
		return (write(2, "malloc_error\n", 13), 0);
	return (1);
}

bool	assign_args(int argc, char **argv, t_data *data)
{
	int				error;

	error = 0;
	data->shared->ttd = str_to_int(argv[2], &error);
	data->shared->tte = str_to_int(argv[3], &error);
	data->shared->tts = str_to_int(argv[4], &error);
	if (argc == 6)
		data->shared->meals_num = str_to_int(argv[5], &error);
	else
		data->shared->meals_num = -1;
	data->shared->stop = 0;
	if (error || data->shared->ttd < 0
		|| data->shared->tte < 0 || data->shared->tts < 0
		|| (argc == 6 && data->shared->meals_num < 0))
		return (write(2, "arguments should be positive integers\n", 38), 0);
	return (1);
}

bool	assign_shared(int argc, char **argv, t_data *data)
{
	int				i;

	data->shared = NULL;
	data->shared = malloc(sizeof(t_shared));
	if (!assign_args(argc, argv, data))
		return (0);
	data->shared->fork_mtx = malloc((data->ph_num)
			* sizeof(pthread_mutex_t));
	if (!data->shared->fork_mtx)
		return (free(data->ph), write(2, "malloc_error\n", 13), 0);
	pthread_mutex_init(&data->shared->print_mtx, NULL);
	pthread_mutex_init(&data->shared->dead_mtx, NULL);
	i = 0;
	data->shared->forks = malloc((data->ph_num) * sizeof(int));
	while (i < data->ph_num)
	{
		data->shared->forks[i] = -1;
		if (pthread_mutex_init(&data->shared->fork_mtx[i++], NULL))
		{
			write(2, "error in 	mutex creation\n", 25);
			(free(data->ph), free(data->shared->fork_mtx));
			return (0);
		}
	}
	return (1);
}

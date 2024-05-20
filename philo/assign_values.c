/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:24:37 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 09:06:02 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

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
	while (is_space(str[i]) == 1)
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

bool	assign_values(int argc, char **argv, t_ph *ph)
{
	int	error;

	error = 0;
	if (argc < 5 || argc > 6)
		return (write(2, "program takes only 4 or 5 integer values\n", 41), 0);
	ph->ph_num = str_to_int(argv[1], &error);
	ph->ttd = str_to_int(argv[2], &error);
	ph->tte = str_to_int(argv[3], &error);
	ph->tts = str_to_int(argv[4], &error);
	if (argc == 6)
		ph->eat_num = str_to_int(argv[5], &error);
	else
		ph->eat_num = -1;
	if (error || ph->ph_num <= 0 || ph->ttd < 0 || ph->tte < 0 || ph->tts < 0)
		return (write(2, "arguments should be positive integers\n", 38), 0);		
	return (1);
}

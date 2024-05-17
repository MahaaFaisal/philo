/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:25 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/17 13:32:09 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
 #include <string.h>

typedef struct s_ph
{
	pthread_t		*th;
	pthread_mutex_t	mtx; // !not sure if its needed
	int				ph_num;
	int				ttd;
	int				tte;
	int				tts;
	int				eat_num;
}	t_ph;

bool	assign_values(int argc, char **argv, t_ph *ph);
int		str_to_int(const char *str, int *error);




//? ------------- debuggers --------------------
void	print_philo(t_ph *ph);
#endif

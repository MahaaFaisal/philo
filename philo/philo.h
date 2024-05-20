/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:25 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/20 14:46:50 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_ph
{
	pthread_t		*th;
	pthread_mutex_t	*fork_mtx;
	int				ph_num;
	int				ttd;
	int				tte;
	int				tts;
	int				eat_num;
	long			start_ms;
}	t_ph;

// --------- initialize threads ---------------
bool	assign_values(int argc, char **argv, t_ph *ph);
int		str_to_int(const char *str, int *error);
bool	create_threads(t_ph *ph);

// ---------- time functions ----------------
long	getmillitime(struct timeval time);
int		getelapsedtime(long start_ms);
// ---------- routine function ----------------
void	*eat_think_sleep(void *ph);

// ---------- terminate_threads ---------------
bool	join_threads(t_ph *ph);

// ------------- debuggers --------------------
void	print_philo(t_ph *ph);
#endif

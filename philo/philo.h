/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:25 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/22 11:05:09 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"

typedef struct s_shared	t_shared;
typedef struct s_ph
{
	pthread_t		th;
	int				id;
	long			last_meal;
	t_shared		*shared;
}	t_ph;

typedef struct s_shared
{
	t_ph			*ph;
	pthread_mutex_t	*fork_mtx;
	int				*forks;
	int				ph_num;
	int				ttd;
	int				tte;
	int				tts;
	int				eat_num;
	long			start_ms;
	int				dead;
}	t_shared;

// --------- initialize threads ---------------
bool	assign_values(int argc, char **argv, t_shared *shared);
int		str_to_int(const char *str, int *error);
bool	create_threads(t_shared *ph);

// ---------- time functions ----------------
long	getmillitime(struct timeval time);
int		getelapsedtime(long start_ms);
// ---------- routine function ----------------
void	*eat_think_sleep(void *shared);

// ---------- terminate_threads ---------------
bool	join_threads(t_shared *shared);

// ------------- debuggers --------------------
// void	print_philo(t_shared *shared);
#endif

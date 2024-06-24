/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:42:25 by mafaisal          #+#    #+#             */
/*   Updated: 2024/06/24 17:20:06 by mafaisal         ###   ########.fr       */
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

typedef struct s_shared
{
	pthread_mutex_t	*fork_mtx;
	int				*forks;
	int				ttd;
	int				tte;
	int				tts;
	pthread_mutex_t	dead_mtx;
	int				dead;
	pthread_mutex_t	print_mtx;
	long			start_ms;
	int				meals_num;
}	t_shared;

typedef struct s_ph
{
	pthread_t		th;
	int				id;
	int				meals_num;
	long			last_meal;
	pthread_mutex_t	*first_mutex;
	int				*first_fork;
	pthread_mutex_t	*sec_mutex;
	int				*sec_fork;
	t_shared		*shared;
	int				dead;
}	t_ph;

typedef struct s_data // should be named data
{
	int				ph_num;
	t_ph			*ph;
	t_shared		*shared;
}	t_data;

// --------- initialize threads ---------------
bool	assign_data(int argc, char **argv, t_data *data);
bool	assign_shared(int argc, char **argv, t_data *data);
int		str_to_int(const char *str, int *error);
bool	create_philos(t_data *ph);

// ---------- time functions ----------------
long	getmillitime(struct timeval time);
int		getelapsedtime(long start_ms);
long	getmillinow(void);

// --------------- monitors -------------------
bool	should_die(t_ph *ph);
bool	should_stop(t_shared *shared);

// ---------- routine function ----------------
void	*eat_think_sleep(void *data);
void	print_action(t_ph *ph, char *action, char *color);

// ---------- terminate_threads ---------------
bool	end_program(t_data *data);
void	free_memory(t_data *data);
bool	destroy_mutexes(t_data *data);
// ------------- debuggers --------------------
// void	print_philo(t_data *data);

#endif

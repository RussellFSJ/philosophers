/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:05:22 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/28 23:54:20 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum s_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_constr
{
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		no_of_meals;
	int		simulation_end;
}	t_constr;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	long			last_meal_ts;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_status		status;
	t_constr		*constrs;
}	t_philo;

void			print_usage(void);
int				valid_args(int argc, char **argv);
void			forks_cleanup(pthread_mutex_t *forks, int no_of_philos);
t_constr		*constrs_init(int argc, char **argv);
pthread_mutex_t	*forks_init(int no_of_philos);
t_philo			**philos_init(int argc, t_constr *constrs);
void			monitor_routine(pthread_t monitor, t_constr *constrs);
void			philo_routine(t_philo philo);
void			start_routines(t_philo *philos, int no_of_ph, t_constr *cnstrs);
int				start_threads(t_philo *philos, int no_of_ph, t_constr *cnstrs);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_isnbr(const char *s);
long			get_time_in_ms(void);
void			handle_error(char *err_msg);

#endif
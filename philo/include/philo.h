/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:05:22 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:56:59 by rfoo             ###   ########.fr       */
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
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_constr
{
	int				no_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				no_of_meals;
	int				simulation_start;
	int				simulation_end;
	long			simulation_start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	*forks;
}	t_constr;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				has_left_fork;
	int				has_right_fork;
	long			last_meal_ts;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_status		status;
	t_constr		*constrs;
}	t_philo;

void		print_usage(void);
int			valid_args(int argc, char **argv);
void		cleanup(t_philo *philos, t_constr *constrs);
void		constrs_cleanup(t_constr *constrs);
void		forks_cleanup(t_constr *constrs);
void		mutexes_cleanup(t_constr *constrs);
void		philos_cleanup(t_philo *philos);
t_constr	*constrs_init(int argc, char **argv);
int			forks_init(t_constr *constrs);
t_philo		*philos_init(t_constr *constrs);
void		*monitor_routine(void *arg);
void		philo_eat(t_philo *philo);
void		*philo_routine(void *arg);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		start_simulation(t_philo *philos, t_constr *constr);
int			start_threads(t_philo *philos, t_constr *constrs);
void		wait_for_start(t_constr *constrs);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
int			ft_isdigit(int c);
int			ft_isnbr(const char *s);
long		get_time_in_ms(void);
void		handle_error(char *err_msg);
void		print_status(int id, t_status status, t_constr *constrs);
int			safe_read(pthread_mutex_t *mutex, int *flag);
void		safe_update(pthread_mutex_t *mutex, int *flag, int value);
void		smart_sleep(t_constr *constrs, long duration);

#endif
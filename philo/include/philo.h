/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:05:22 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/18 00:18:25 by rfoo             ###   ########.fr       */
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

typedef struct s_constr
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	no_of_meals;
}	t_constr;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				last_meal_ts;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_constr		*constrs;
}	t_philo;

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	ft_isnbr(const char *s);

#endif
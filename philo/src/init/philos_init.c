/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:17:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/18 22:10:29 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_philo *philo);

t_philo	*philos_init(t_constr *constrs)
{
	int				i;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	i = 0;
	philos = malloc(sizeof(t_philo) * constrs->no_of_philos);
	if (!philos)
		return (NULL);
	forks = constrs->forks;
	if (!forks)
		return (NULL);
	while (i < constrs->no_of_philos)
	{
		philo_init(&philos[i]);
		philos[i].id = i + 1;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % constrs->no_of_philos];
		philos[i].constrs = constrs;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
	return (philos);
}

static void	philo_init(t_philo *philo)
{
	philo->meal_count = 0;
	philo->has_left_fork = 0;
	philo->has_right_fork = 0;
	philo->last_meal_ts = get_time_in_ms();
	philo->thread = 0;
	philo->status = THINKING;
}

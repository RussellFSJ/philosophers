/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:56:54 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 22:35:34 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo_routine(void *arg);
static void	join_created_threads(t_philo *philos, int count);

int	start_threads(t_philo *philos, t_constr *constrs)
{
	int	i;

	i = 0;
	if (constrs->no_of_philos == 1)
	{
		if (pthread_create(&philos[0].thread, NULL,
				one_philo_routine, &philos[0]) != 0)
			return (printf("Error: Failed to create philosopher thread.\n"), 0);
		pthread_join(philos[0].thread, NULL);
		return (1);
	}
	while (i < constrs->no_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i])
			!= 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			safe_update(&constrs->end_mutex, &constrs->simulation_end, 1);
			return (join_created_threads(philos, i), 0);
		}
		i++;
	}
	return (1);
}

static void	*one_philo_routine(void *arg)
{
	t_philo		*philo;
	t_constr	*constrs;

	philo = (t_philo *)arg;
	constrs = philo->constrs;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->id, TAKEN_FORK, constrs);
	smart_sleep(constrs, constrs->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
	safe_update(&constrs->end_mutex, &constrs->simulation_end, 1);
	print_status(philo->id, DEAD, constrs);
	return (NULL);
}

static void	join_created_threads(t_philo *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
		pthread_join(philos[i++].thread, NULL);
}

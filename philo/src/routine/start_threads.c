/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:56:54 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/12 06:11:52 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo_routine(void *arg);

int	start_threads(t_philo *philos, int no_of_ph, t_constr *cnstrs)
{
	int	i;

	i = 0;
	if (no_of_ph == 1)
	{
		pthread_create(&philos[0].thread, NULL, one_philo_routine, &philos[0]);
		pthread_join(philos[0].thread, NULL);
		return (1);
	}
	while (i < no_of_ph)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i])
			!= 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			cnstrs->simulation_end = 1;
			return (0);
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
	print_status(philo->id, DEAD, constrs);
	pthread_mutex_unlock(philo->left_fork);
	constrs->simulation_end = 1;
	return (NULL);
}

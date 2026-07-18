/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:43:05 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/19 00:16:59 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_start(t_constr *constrs);

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		simulation_end;

	philo = (t_philo *)arg;
	wait_for_start(philo->constrs);
	if (philo->id % 2 == 0)
		usleep(2000);
	while (1)
	{
		pthread_mutex_lock(&philo->constrs->end_mutex);
		simulation_end = philo->constrs->simulation_end;
		pthread_mutex_unlock(&philo->constrs->end_mutex);
		if (simulation_end)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(200);
	}
	return (NULL);
}

static void	wait_for_start(t_constr *constrs)
{
	int	started;

	started = 0;
	while (!started)
	{
		pthread_mutex_lock(&constrs->start_mutex);
		started = constrs->simulation_start;
		pthread_mutex_unlock(&constrs->start_mutex);
		if (!started)
			usleep(200);
	}
}

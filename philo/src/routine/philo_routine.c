/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:43:05 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/15 16:06:48 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_start(t_constr *constrs);

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_for_start(philo->constrs);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->constrs->simulation_end)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(philo->constrs->time_to_eat / 2);
	}
	return (NULL);
}

static void	wait_for_start(t_constr *constrs)
{
	while (!constrs->simulation_start)
		usleep(100);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:43:05 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/02 00:16:06 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void wait_for_start(t_constr *constrs);

void	philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_for_start(philo->constrs);
	while (!philo->constrs->simulation_end)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		philo->last_meal_ts = get_timestamp();
		philo->meal_count++;
		philo->status = EATING;
	
	}
	return ;
}
static void wait_for_start(t_constr *constrs)
{
	while (!constrs->simulation_start)
		usleep(100);
}
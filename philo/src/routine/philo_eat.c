/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:43:00 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/16 17:53:47 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo);
static void	release_forks(t_philo *philo);

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_ts = get_time_in_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	philo->status = EATING;
	print_status(philo->id, philo->status, philo->constrs);
	smart_sleep(philo->constrs, philo->constrs->time_to_eat);
	release_forks(philo);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo->id, TAKEN_FORK, philo->constrs);
		if (philo->constrs->simulation_end)
			return ;
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo->id, TAKEN_FORK, philo->constrs);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo->id, TAKEN_FORK, philo->constrs);
		if (philo->constrs->simulation_end)
			return ;
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo->id, TAKEN_FORK, philo->constrs);
	}
}

static void	release_forks(t_philo *philo)
{
	if (philo->has_left_fork)
		pthread_mutex_unlock(philo->left_fork);
	if (philo->has_right_fork)
		pthread_mutex_unlock(philo->right_fork);
	philo->has_left_fork = 0;
	philo->has_right_fork = 0;
}

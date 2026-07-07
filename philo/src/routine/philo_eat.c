/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:43:00 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/07 22:04:51 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo);
static void	release_forks(t_philo *philo);

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo->last_meal_ts = get_timestamp();
	philo->meal_count++;
	philo->status = EATING;
	print_status(philo->id, philo->status, philo->constrs);
	smart_sleep(philo->constrs, philo->constrs->time_to_eat);
	release_forks(philo);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->status = TAKEN_FORK;
		print_status(philo->id, philo->status, philo->constrs);
		pthread_mutex_lock(philo->right_fork);
		philo->status = TAKEN_FORK;
		print_status(philo->id, philo->status, philo->constrs);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->status = TAKEN_FORK;
		print_status(philo->id, philo->status, philo->constrs);
		pthread_mutex_lock(philo->left_fork);
		philo->status = TAKEN_FORK;
		print_status(philo->id, philo->status, philo->constrs);
	}
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

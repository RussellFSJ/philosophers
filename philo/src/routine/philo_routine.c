/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:43:05 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/28 19:02:32 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo philo)
{
	while (!philo.constrs->simulation_end)
	{
		pthread_mutex_lock(philo.left_fork);
		pthread_mutex_lock(philo.right_fork);

		philo.last_meal_ts = get_timestamp();
		philo.meal_count++;
		philo.status = EATING;
		

	}
	return ;
}

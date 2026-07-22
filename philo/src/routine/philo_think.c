/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:15:04 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/22 16:28:02 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	philo->status = THINKING;
	print_status(philo->id, philo->status, philo->constrs);
	if (philo->constrs->no_of_philos % 2 == 1)
		smart_sleep(philo->constrs, philo->constrs->time_to_eat / 2);
}

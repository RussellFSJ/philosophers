/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:22:58 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/07 21:17:03 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEPING;
	print_status(philo->id, philo->status, philo->constrs);
	smart_sleep(philo->constrs, philo->constrs->time_to_sleep);
}

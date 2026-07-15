/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:24:14 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/15 17:21:23 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philo *philos, t_constr *constr)
{
	int	i;

	constr->simulation_start_time = get_time_in_ms();
	constr->simulation_start = 1;
	i = 0;
	while (i < constr->no_of_philos)
		philos[i++].last_meal_ts = constr->simulation_start_time;
}

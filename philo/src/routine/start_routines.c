/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:10:58 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/09 16:42:09 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routines(t_philo *philos, int no_of_ph, t_constr *cnstrs)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (!start_threads(philos, no_of_ph, cnstrs))
		return ;
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		printf("Error: Failed to create monitor thread.\n");
		cnstrs->simulation_end = 1;
		return ;
	}
	while (i < no_of_ph)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:56:54 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/26 06:06:29 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_philo *philos, int no_of_ph, t_constr *cnstrs)
{
	int	i;

	i = 0;
	while (i < no_of_ph)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i])
			!= 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			cnstrs->simulation_end = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

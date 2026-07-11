/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:17:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/09 16:52:41 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos_init(int no_of_philos, t_constr *constrs)
{
	int				i;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	i = 0;
	philos = malloc(sizeof(t_philo) * no_of_philos);
	if (!philos)
		return (NULL);
	forks = forks_init(no_of_philos);
	if (!forks)
		return (NULL);
	while (i < no_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meal_count = 0;
		philos[i].last_meal_ts = get_time_in_ms();
		philos[i].thread = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % no_of_philos];
		philos[i].constrs = constrs;
		i++;
	}
	return (philos);
}

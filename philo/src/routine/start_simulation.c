/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:10:58 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/19 00:14:18 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	begin_simulation(t_philo *philos, t_constr *constr);
static void	join_philos(t_philo *philos);

void	start_simulation(t_philo *philos, t_constr *constrs)
{
	pthread_t	monitor;

	if (!start_threads(philos, constrs))
		return ;
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		printf("Error: Failed to create monitor thread.\n");
		pthread_mutex_lock(&constrs->end_mutex);
		constrs->simulation_end = 1;
		pthread_mutex_unlock(&constrs->end_mutex);
		pthread_mutex_lock(&constrs->start_mutex);
		constrs->simulation_start = 1;
		pthread_mutex_unlock(&constrs->start_mutex);
		join_philos(philos);
		return ;
	}
	begin_simulation(philos, constrs);
	join_philos(philos);
	pthread_join(monitor, NULL);
}

static void	begin_simulation(t_philo *philos, t_constr *constrs)
{
	long	start;
	int		i;

	start = get_time_in_ms();
	constrs->simulation_start_time = start;
	i = 0;
	while (i < constrs->no_of_philos)
		philos[i++].last_meal_ts = start;
	pthread_mutex_lock(&constrs->start_mutex);
	constrs->simulation_start = 1;
	pthread_mutex_unlock(&constrs->start_mutex);
}

static void	join_philos(t_philo *philos)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (i < philos[0].constrs->no_of_philos)
		pthread_join(philos[i++].thread, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:38:26 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 22:34:57 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_died(t_philo *philos);
static int	all_philos_full(t_philo *philos);

void	*monitor_routine(void *arg)
{
	t_philo		*philos;
	t_constr	*constrs;
	int			simulation_end;

	philos = (t_philo *)arg;
	constrs = philos[0].constrs;
	simulation_end = safe_read(&constrs->end_mutex, &constrs->simulation_end);
	while (!simulation_end)
	{
		if (philo_died(philos) || all_philos_full(philos))
			break ;
		usleep(100);
		simulation_end = safe_read(&constrs->end_mutex,
				&constrs->simulation_end);
	}
	return (NULL);
}

static int	philo_died(t_philo *philos)
{
	int			i;
	t_constr	*constrs;
	long		now;

	i = 0;
	constrs = philos[0].constrs;
	while (i < constrs->no_of_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		now = get_time_in_ms();
		if (now - philos[i].last_meal_ts > constrs->time_to_die)
		{
			pthread_mutex_unlock(&philos[i].meal_mutex);
			print_status(philos[i].id, DEAD, constrs);
			safe_update(&constrs->end_mutex, &constrs->simulation_end, 1);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (0);
}

static int	all_philos_full(t_philo *philos)
{
	int			i;
	t_constr	*constrs;
	int			all_full;

	i = 0;
	constrs = philos[0].constrs;
	all_full = 1;
	if (constrs->no_of_meals < 0)
		return (0);
	while (i < constrs->no_of_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].meal_count < constrs->no_of_meals)
			all_full = 0;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	if (all_full)
	{
		safe_update(&constrs->end_mutex, &constrs->simulation_end, 1);
		return (1);
	}
	return (0);
}

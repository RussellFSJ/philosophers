/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:05:06 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/17 00:05:22 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	non_zero_constraints(int argc, t_constr *constrs);

t_constr	*constrs_init(int argc, char **argv)
{
	t_constr		*constrs;

	constrs = malloc(sizeof(t_constr));
	if (!constrs)
		return (NULL);
	constrs->no_of_philos = ft_atoi(argv[1]);
	constrs->time_to_die = ft_atol(argv[2]);
	constrs->time_to_eat = ft_atol(argv[3]);
	constrs->time_to_sleep = ft_atol(argv[4]);
	constrs->simulation_start = 0;
	constrs->simulation_end = 0;
	pthread_mutex_init(&constrs->print_mutex, NULL);
	pthread_mutex_init(&constrs->sim_end_mutex, NULL);
	constrs->forks = forks_init(constrs->no_of_philos);
	if (argc == 6)
		constrs->no_of_meals = ft_atoi(argv[5]);
	else
		constrs->no_of_meals = -1;
	if (!non_zero_constraints(argc, constrs))
	{
		free(constrs);
		return (NULL);
	}
	return (constrs);
}

static int	non_zero_constraints(int argc, t_constr *constrs)
{
	if (constrs->no_of_philos <= 0 || constrs->time_to_die <= 0
		|| constrs->time_to_eat <= 0 || constrs->time_to_sleep <= 0
		|| (argc == 6 && constrs->no_of_meals <= 0))
		return (0);
	return (1);
}

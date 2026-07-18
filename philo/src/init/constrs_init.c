/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:05:06 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/18 23:09:30 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parse_constraints(int argc, char **argv, t_constr *constrs);
static int	non_zero_constraints(t_constr *constrs);
static int	mutexes_init(t_constr *constrs);

t_constr	*constrs_init(int argc, char **argv)
{
	t_constr		*constrs;

	constrs = malloc(sizeof(t_constr));
	if (!constrs)
		return (NULL);
	memset(constrs, 0, sizeof(t_constr));
	parse_constraints(argc, argv, constrs);
	if (!non_zero_constraints(constrs))
		return (free(constrs), NULL);
	if (!mutexes_init(constrs))
		return (free(constrs), NULL);
	if (!forks_init(constrs))
		return (mutexes_cleanup(constrs), free(constrs), NULL);
	return (constrs);
}

static void	parse_constraints(int argc, char **argv, t_constr *constrs)
{
	constrs->no_of_philos = ft_atoi(argv[1]);
	constrs->time_to_die = ft_atol(argv[2]);
	constrs->time_to_eat = ft_atol(argv[3]);
	constrs->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		constrs->no_of_meals = ft_atoi(argv[5]);
	else
		constrs->no_of_meals = -1;
}

static int	non_zero_constraints(t_constr *constrs)
{
	if (constrs->no_of_philos <= 0 || constrs->time_to_die <= 0
		|| constrs->time_to_eat <= 0 || constrs->time_to_sleep <= 0
		|| constrs->no_of_meals == 0)
		return (0);
	return (1);
}

static int	mutexes_init(t_constr *constrs)
{
	if (pthread_mutex_init(&constrs->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&constrs->start_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&constrs->print_mutex);
		return (0);
	}
	if (pthread_mutex_init(&constrs->end_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&constrs->start_mutex);
		pthread_mutex_destroy(&constrs->print_mutex);
		return (0);
	}
	return (1);
}

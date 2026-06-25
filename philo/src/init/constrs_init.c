/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:05:06 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/25 19:01:19 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_constr	*constrs_init(int argc, char **argv)
{
	t_constr	*constrs;

	constrs = malloc(sizeof(t_constr));
	if (!constrs)
		return (NULL);
	constrs->time_to_die = ft_atoi(argv[2]);
	constrs->time_to_eat = ft_atoi(argv[3]);
	constrs->time_to_sleep = ft_atoi(argv[4]);
	constrs->simulation_end = 0;
	if (argc == 6)
		constrs->no_of_meals = ft_atoi(argv[5]);
	else
		constrs->no_of_meals = -1;
	if (constrs->time_to_die <= 0 || constrs->time_to_eat <= 0
		|| constrs->time_to_sleep <= 0
		|| (argc == 6 && constrs->no_of_meals <= 0))
	{
		free(constrs);
		return (NULL);
	}
	return (constrs);
}

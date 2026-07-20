/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:40:48 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:21:12 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_constr	*constrs;
	t_philo		*philos;

	if (!valid_args(argc, argv))
		return (EXIT_FAILURE);
	constrs = constrs_init(argc, argv);
	if (!constrs)
	{
		printf("Error: Failed to initialise contraints.\n");
		return (EXIT_FAILURE);
	}
	philos = philos_init(constrs);
	if (!philos)
	{
		constrs_cleanup(constrs);
		return (EXIT_FAILURE);
	}
	start_simulation(philos, constrs);
	cleanup(philos, constrs);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:40:48 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/22 17:50:01 by rfoo             ###   ########.fr       */
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
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

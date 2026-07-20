/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 22:52:12 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:20:37 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_philo *philos, t_constr *constrs)
{
	if (philos)
		philos_cleanup(philos);
	if (constrs)
		constrs_cleanup(constrs);
}

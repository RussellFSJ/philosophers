/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:38:26 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/26 06:07:48 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_routine(pthread_t monitor, t_constr *constrs)
{
	if (constrs->simulation_end)
	{
		pthread_detach(monitor);
		return ;
	}
}

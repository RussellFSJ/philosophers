/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:48:47 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/07 00:01:13 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(t_constr *constrs, long duration)
{
	long	start;
	long 	now;

	start = get_time_in_ms();
	while (!constrs->simulation_end)
	{
		now = get_time_in_ms();
		if (now - start >= duration)
			return ;
		usleep(100);
	}
}

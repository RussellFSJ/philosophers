/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:48:47 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/16 22:38:33 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(t_constr *constrs, long duration)
{
	long	start;
	long	now;
	int		simulation_end;

	start = get_time_in_ms();
	pthread_mutex_lock(&constrs->sim_end_mutex);
	simulation_end = constrs->simulation_end;
	pthread_mutex_unlock(&constrs->sim_end_mutex);
	while (!simulation_end)
	{
		now = get_time_in_ms();
		if (now - start >= duration)
			return ;
		usleep(100);
	}
}

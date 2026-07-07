/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:14:42 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/07 21:51:57 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int id, t_status status, t_constr *constrs)
{
	long	timestamp;

	timestamp = get_time_in_ms() - constrs->simulation_start_time;
	pthread_mutex_lock(&constrs->print_mutex);
	if (!constrs->simulation_end)
	{
		if (status == TAKEN_FORK)
			printf("%ld %d has taken a fork\n", timestamp, id);
		else if (status == EATING)
			printf("%ld %d is eating\n", timestamp, id);
		else if (status == SLEEPING)
			printf("%ld %d is sleeping\n", timestamp, id);
		else if (status == EATING)
			printf("%ld %d is thinking\n", timestamp, id);
		else if (status == DEAD)
			printf("%ld %d died\n", timestamp, id);
	}
	pthread_mutex_unlock(&constrs->print_mutex);
}

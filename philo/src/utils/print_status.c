/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:14:42 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/28 23:58:51 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int id, char *status)
{
	long	timestamp;

	timestamp = get_time_in_ms();
	printf("%ld %d is %s\n", timestamp, id, status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:59:47 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/28 23:53:16 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);	
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

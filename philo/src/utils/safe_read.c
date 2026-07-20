/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:34:46 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 21:25:04 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	safe_read(pthread_mutex_t *mutex, int *flag)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *flag;
	pthread_mutex_unlock(mutex);
	return (value);
}

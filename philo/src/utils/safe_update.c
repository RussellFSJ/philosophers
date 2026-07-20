/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:19:46 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 20:34:10 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_update(pthread_mutex_t *mutex, int *flag, int value)
{
	pthread_mutex_lock(mutex);
	*flag = value;
	pthread_mutex_unlock(mutex);
}

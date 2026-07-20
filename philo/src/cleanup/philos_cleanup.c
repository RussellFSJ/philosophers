/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 23:59:34 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:20:54 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_cleanup(t_philo *philos)
{
	int	i;

	i = 0;
	if (!philos)
		return ;
	while (i < philos[0].constrs->no_of_philos)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(philos);
}

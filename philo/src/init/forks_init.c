/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:04:10 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/22 22:42:52 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*forks_init(int no_of_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * no_of_philos);
	if (!forks)
		return (NULL);
	while (i < no_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			forks_cleanup(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

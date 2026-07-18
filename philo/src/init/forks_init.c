/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:04:10 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/18 21:23:09 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*create_forks(int no_of_philos);

int	forks_init(t_constr *constrs)
{
	constrs->forks = create_forks(constrs->no_of_philos);
	if (!constrs->forks)
		return (0);
	return (1);
}

static pthread_mutex_t	*create_forks(int no_of_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	if (no_of_philos == 0)
		return (NULL);
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

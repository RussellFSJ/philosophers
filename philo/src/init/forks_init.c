/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:04:10 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:22:53 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*create_forks(t_constr *constrs);

int	forks_init(t_constr *constrs)
{
	constrs->forks = create_forks(constrs);
	if (!constrs->forks)
		return (0);
	return (1);
}

static pthread_mutex_t	*create_forks(t_constr *constrs)
{
	int				i;
	pthread_mutex_t	*forks;

	if (constrs->no_of_philos == 0)
		return (NULL);
	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * constrs->no_of_philos);
	if (!forks)
		return (NULL);
	while (i < constrs->no_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			forks_cleanup(constrs);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 21:04:41 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/18 23:09:58 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexes_cleanup(t_constr *constrs)
{
	pthread_mutex_destroy(&constrs->print_mutex);
	pthread_mutex_destroy(&constrs->start_mutex);
	pthread_mutex_destroy(&constrs->end_mutex);
}

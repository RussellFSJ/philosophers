/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrs_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:01:30 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/20 23:16:58 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	constrs_cleanup(t_constr *constrs)
{
	if (!constrs)
		return ;
	forks_cleanup(constrs);
	mutexes_cleanup(constrs);
	free(constrs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:49:10 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/21 00:06:22 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Error: Please enter 4 or 5 positive numeric arguments.\n");
		print_usage();
		return (0);
	}
	while (i < argc)
	{
		if (!ft_isnbr(argv[i]))
		{
			printf("Error: Please provide positive numeric arguments.\n");
			print_usage();
			return (0);
		}
		i++;
	}
	return (1);
}

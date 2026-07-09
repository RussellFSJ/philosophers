/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:49:10 by rfoo              #+#    #+#             */
/*   Updated: 2026/07/09 16:11:04 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Please enter 4 or 5 numeric arguments.\n");
		print_usage();
		return (0);
	}
	if (!ft_isnbr(argv[1]) || !ft_isnbr(argv[2])
		|| !ft_isnbr(argv[3]) || !ft_isnbr(argv[4]))
	{
		printf("Error: Please provide numeric arguments.\n");
		print_usage();
		return (0);
	}
	return (1);
}

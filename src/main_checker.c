/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:30:01 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 01:23:50 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int res;

	if (argc == 1)
	{
		ft_printf("Nothing\n");
		return (0);
	}
	if ((res = checker(argc, argv)) == -2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (res == -1)
	{
		ft_printf("KO\n");
		return (0);
	}
	ft_printf("OK\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:26:23 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 01:24:07 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Nothing\n");
		return (0);
	}
	if (push_swap(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:08:10 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/29 22:02:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_list(t_list list)
{
	int i;

	i = 0;
	ft_printf("a =");
	while (i < list.s1)
	{
		ft_printf(" %d", list.lista[i]);
		i++;
	}
	ft_printf("\n\nb=");
	i = 0;
	while (i < list.s2)
	{
		ft_printf(" %d", list.listb[i]);
		i++;
	}
	ft_printf("\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:39:23 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:51:30 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rrotate_b(t_list *list, int print)
{
	int		*dup;
	int		i;

	i = 1;
	if ((*list).s2 < 2)
		return (-1);
	if (print == 1)
		ft_printf("rrb\n");
	if (!(dup = (int *)malloc(sizeof(int) * (*list).s2)))
		return (-2);
	dup = ft_memcpy_push(dup, (*list).listb, (*list).s2);
	(*list).listb[0] = dup[(*list).s2 - 1];
	while (i < (*list).s2)
	{
		(*list).listb[i] = dup[i - 1];
		i++;
	}
	free(dup);
	return (0);
}

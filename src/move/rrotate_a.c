/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:56:59 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:46:00 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rrotate_a(t_list *list, int print)
{
	int		*dup;
	int		i;

	i = 1;
	if ((*list).s1 < 2)
		return (-1);
	if (print == 1)
		ft_printf("rra\n");
	if (!(dup = (int *)malloc(sizeof(int) * (*list).s1)))
		return (-2);
	dup = ft_memcpy_push(dup, (*list).lista, (*list).s1);
	(*list).lista[0] = dup[(*list).s1 - 1];
	while (i < (*list).s1)
	{
		(*list).lista[i] = dup[i - 1];
		i++;
	}
	free(dup);
	return (0);
}

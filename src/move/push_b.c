/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:40:33 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:47:43 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		remove_lista(t_list *list)
{
	int		save;
	int		*dup;

	save = 0;
	if (!(dup = (int *)malloc(sizeof(int) * (*list).s1)))
		return (-1);
	dup = ft_memcpy_push(dup, (*list).lista, (*list).s1);
	while (save != (*list).s1 - 1)
	{
		(*list).lista[save] = dup[save + 1];
		save++;
	}
	free(dup);
	(*list).s1--;
	return (0);
}

int		add_listb(t_list *list)
{
	int		save;
	int		*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (*list).s2)))
		return (-1);
	dup = ft_memcpy_push(dup, (*list).listb, (*list).s2);
	save = (*list).s2;
	while (save > 0)
	{
		(*list).listb[save] = dup[save - 1];
		save--;
	}
	free(dup);
	(*list).listb[0] = (*list).lista[0];
	(*list).s2++;
	return (0);
}

int		push_b(t_list *list, int print)
{
	if ((*list).s1 < 1)
		return (-1);
	if (print == 1)
		ft_printf("pb\n");
	if (add_listb(list) == -1)
		return (-2);
	if (remove_lista(list) == -1)
		return (-2);
	return (0);
}

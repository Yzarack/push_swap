/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sortlistb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:39:01 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 20:44:27 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_with_hi(t_list list, int hi)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (list.listb[i] != hi)
		i++;
	if (i != list.s2 - 1)
		i++;
	else
		i = 0;
	while (list.listb[i] != hi)
	{
		if (i != 0 && list.listb[i] > list.listb[i - 1])
			return (-1);
		else if (i == 0 && list.listb[i] > list.listb[list.s2 - 1])
			return (-1);
		if (i != list.s2 - 1)
			i++;
		else
			i = 0;
	}
	return (1);
}

int		insertion_algob_part(t_list *list, int *i, int j, int lo)
{
	int hi;

	hi = get_hi_value((*list).listb, (*list).s2);
	if ((i > 0 && (*list).listb[*i - 1] < (*list).listb[*i] &&
	(*list).listb[*i] != hi) || (*i > 0 && (*list).listb[*i]
	== hi && (*list).listb[*i - 1] != lo) || (*i == 0 &&
	(*list).listb[j - 1] < (*list).listb[0] && (*list).listb[0]
	!= hi) || (*i == 0 && (*list).listb[j - 1] == lo &&
	(*list).listb[0] != hi))
	{
		if (*i == 0)
			rotate_to_index(list, j - 1, (*list).listb[j - 1], 'b');
		else
			rotate_to_index(list, *i - 1, (*list).listb[*i - 1], 'b');
		swap_b(list, 1);
		*i = 0;
	}
	else
		*i += 1;
	return (0);
}

int		insertion_algob(t_list *list, int lo, int hi)
{
	int i;
	int j;

	i = 0;
	j = (*list).s2;
	while (sort_with_hi(*list, hi) != 1)
	{
		if ((((*list).listb[i] < (*list).listb[i + 1] &&
		(*list).listb[i + 1] != hi)
		|| ((*list).listb[i + 1] == hi && (*list).listb[i] != lo)) ||
		((*list).listb[i + 1] == lo && (*list).listb[i] == hi))
		{
			rotate_to_index(list, i, (*list).listb[i], 'b');
			swap_b(list, 1);
			i = 0;
		}
		else
			insertion_algob_part(list, &i, j, lo);
	}
	return (0);
}

int		insertion_sortlistb(t_list *list)
{
	int lo;
	int hi;
	int i;

	i = 0;
	lo = get_lo_value((*list).listb, (*list).s2);
	hi = get_hi_value((*list).listb, (*list).s2);
	if ((*list).s2 == 0)
		return (0);
	insertion_algob(list, lo, hi);
	i = 0;
	while ((*list).listb[i] != hi)
		i++;
	rotate_to_index(list, i, hi, 'b');
	return (0);
}

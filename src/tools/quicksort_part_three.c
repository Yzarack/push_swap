/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_part_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:57:35 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 22:19:27 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_rotate(t_list *list, t_pivot *pivot, int lo, int i)
{
	(*pivot).pivot = (((*list).lista[0] +
	get_hi_value((*list).lista, (*list).s1)) / 2);
	if (save_pivot(pivot) == -1)
		return (-1);
	while (list_sort_pivot((*list).lista, (*list).s1, (*pivot).pivot, 1) == -1
	&& (*list).lista[0] != lo)
	{
		while ((*list).lista[0] < (*pivot).pivot && (*list).lista[0] != lo)
			push_b(list, 1);
		if ((*list).lista[0] >= (*pivot).pivot && (*list).lista[0] != lo)
		{
			i++;
			rotate_a(list, 1);
		}
	}
	while (i-- != 0)
		rrotate_a(list, 1);
	return (0);
}

void	push_quicksort_part_three(t_list *list, t_pivot *pivot, int i, int lo)
{
	while (list_sort_pivot((*list).lista, (*list).s1, (*pivot).tab_pivot[i],
	1) == -1 && (*list).lista[0] != lo && i != 0)
	{
		if ((*list).lista[0] > (*list).lista[1] && (*list).s2 > 1 &&
		(*list).listb[0] < (*list).listb[1] && (*list).lista[0] !=
		lo && (*list).lista[1] != lo)
			swap_swap(list, 1);
		else if ((*list).lista[0] > (*list).lista[1]
		&& lo != (*list).lista[1])
			swap_a(list, 1);
		rotate_or_not(list);
		while ((*list).lista[0] < (*pivot).tab_pivot[i] && lo !=
		(*list).lista[0])
		{
			push_b(list, 1);
			rotate_or_not(list);
		}
	}
}

int		quicksort_part_three(t_list *list, t_pivot *pivot)
{
	int lo;
	int	test;

	test = (*pivot).size;
	lo = get_lo_value((*list).lista, (*list).s1);
	while ((*list).s2 == 0 && (*list).lista[0] != lo &&
	test != -1 && one_list_sort((*list).lista, (*list).s1) == -1 && test != 0)
	{
		test--;
		push_quicksort_part_three(list, pivot, test, lo);
		if (test == 0)
			test_rotate(list, pivot, lo, 0);
	}
	quicksort_part_two(list, pivot);
	return (0);
}

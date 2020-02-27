/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:18:02 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 22:03:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		quicksort_part_two(t_list *list, t_pivot *pivot)
{
	int lo;

	lo = get_lo_value((*list).lista, (*list).s1);
	while ((*list).s2 > 3 && one_listb_sort((*list).listb, (*list).s2) == -1)
	{
		(*pivot).pivot = choose_pivot((*list).listb, (*list).s2, 2);
		if (save_pivot(pivot) == -1)
			return (-1);
		while (listb_sort_pivot((*list).listb, (*list).s2, (*pivot).pivot)
		== -1)
		{
			rotate_or_not(list);
			while ((*list).listb[0] > (*pivot).pivot && (*list).s2 > 0)
			{
				push_a(list, 1);
				rotate_or_not(list);
			}
			if (listb_sort_pivot((*list).listb, (*list).s2,
			(*pivot).pivot) == -1)
				rotate_b(list, 1);
		}
	}
	insertion_sortlistb(list);
	return (0);
}

int		quicksort_body(t_list *list, t_pivot *pivot)
{
	int		j;

	quicksort_part_two(list, pivot);
	j = (*list).s2;
	while ((*list).s2 != 0)
		push_a(list, 1);
	while (j > 0)
	{
		rotate_a(list, 1);
		j--;
	}
	while (check_list_sort(*list) == -1)
	{
		quicksort_part_three(list, pivot);
		while ((*list).s2 != 0)
			push_a(list, 1);
		rotate_or_not(list);
		if (one_list_sort((*list).lista, (*list).s1) == 1 && (*list).s2 == 0)
		{
			while (check_list_sort(*list) == -1)
				rotate_a(list, 1);
		}
	}
	return (0);
}

int		quicksort_part_one(t_list *list)
{
	int		j;
	t_pivot pivot;

	j = 0;
	pivot.size = -1;
	pivot.pivot = get_hi_value((*list).lista, (*list).s1) + 1;
	save_pivot(&pivot);
	pivot.pivot = choose_pivot((*list).lista, (*list).s1, 2);
	if (save_pivot(&pivot) == -1)
		return (-1);
	while (list_sort_pivot((*list).lista, (*list).s1,
	pivot.pivot, 0) == -1)
	{
		while ((*list).lista[0] < pivot.pivot)
			push_b(list, 1);
		if (list_sort_pivot((*list).lista, (*list).s1,
		pivot.pivot, 0) == -1)
			rotate_a(list, 1);
	}
	quicksort_body(list, &pivot);
	free(pivot.tab_pivot);
	return (0);
}

int		push_swap(int argc, char **argv)
{
	t_list	list;

	list.s2 = 0;
	if (create_list(argc, argv, &list) == -1)
		return (-1);
	if (list.s1 < 11)
		insertion_sort(&list, 0);
	else if (quicksort_part_one(&list) == -1)
		return (-1);
	free(list.lista);
	free(list.listb);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:28:44 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 12:05:32 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_with_lo(t_list list, int lo)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (list.lista[i] != lo)
		i++;
	if (i != list.s1 - 1)
		i++;
	else
		i = 0;
	while (list.lista[i] != lo)
	{
		if (i != 0 && list.lista[i] < list.lista[i - 1])
			return (-1);
		else if (i == 0 && list.lista[i] < list.lista[list.s1 - 1])
			return (-1);
		if (i != list.s1 - 1)
			i++;
		else
			i = 0;
	}
	return (1);
}

int		insertion_algo_part(t_list *list, int *i, int status)
{
	int		hi;
	int		lo;

	hi = get_hi_value((*list).lista, (*list).s1);
	lo = get_lo_value((*list).lista, (*list).s1);
	if (((*i > 0 && (*list).lista[*i - 1] > (*list).lista[*i] &&
	(*list).lista[*i - 1] != hi) || (*i > 0 && (*list).lista[*i - 1]
	== hi && (*list).lista[*i] != lo) || (*i == 0 &&
	(*list).lista[(*list).s1 - 1] > (*list).lista[0] &&
	(*list).lista[(*list).s1 - 1] != hi))
	&& status == 0)
	{
		if (*i == 0)
			rotate_to_index(list, (*list).s1 - 1,
			(*list).lista[(*list).s1 - 1], 'a');
		else
			rotate_to_index(list, *i - 1, (*list).lista[*i - 1], 'a');
		swap_a(list, 1);
		*i = 0;
	}
	else
		*i += 1;
	return (0);
}

int		insertion_algo(t_list *list, int lo, int hi, int status)
{
	int i;
	int j;

	i = 0;
	j = (*list).s1;
	while (sort_with_lo(*list, lo) != 1)
	{
		if (((*list).lista[i] > (*list).lista[i + 1] && (*list).lista[i] != hi)
		|| ((*list).lista[i] == hi && (*list).lista[i + 1] != lo) ||
		((*list).lista[i] == lo && (*list).lista[i + 1] == hi))
		{
			rotate_to_index(list, i, (*list).lista[i % j], 'a');
			swap_a(list, 1);
			i = 0;
		}
		else
		{
			insertion_algo_part(list, &i, status);
		}
	}
	return (0);
}

int		insertion_sort(t_list *list, int status)
{
	int lo;
	int hi;
	int i;

	i = 0;
	lo = get_lo_value((*list).lista, (*list).s1);
	hi = get_hi_value((*list).lista, (*list).s1);
	if ((*list).lista[0] == hi && (*list).lista[(*list).s1 - 1] == lo)
	{
		rrotate_a(list, 1);
		swap_a(list, 1);
	}
	insertion_algo(list, lo, hi, status);
	while ((*list).lista[i] != lo)
		i++;
	rotate_to_index(list, i, lo, 'a');
	return (0);
}

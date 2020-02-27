/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_or_not.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:27:52 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 20:58:58 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		last_nb_listb(t_list *list, int lo)
{
	int i;

	i = 0;
	if ((*list).s2 == 0)
		return (-1);
	while (i != (*list).s2)
	{
		if ((*list).listb[(*list).s2 - 1] > (*list).listb[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i != (*list).s1 && (*list).lista[i] != lo)
	{
		if ((*list).listb[(*list).s2 - 1] > (*list).lista[i])
			return (-1);
		i++;
	}
	rrotate_b(list, 1);
	push_a(list, 1);
	rotate_a(list, 1);
	return (0);
}

int		first_nb_listb(t_list *list, int lo)
{
	int i;

	i = 0;
	if ((*list).s2 == 0)
		return (-1);
	while (i != (*list).s2)
	{
		if ((*list).listb[0] > (*list).listb[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i != (*list).s1 && (*list).lista[i] != lo)
	{
		if ((*list).listb[0] > (*list).lista[i])
			return (-1);
		i++;
	}
	push_a(list, 1);
	rotate_a(list, 1);
	return (0);
}

int		first_nb_lista(t_list *list, int lo)
{
	int i;

	i = 0;
	if (one_list_sort((*list).lista, (*list).s1) == 1)
		return (-1);
	while (i != (*list).s2)
	{
		if ((*list).lista[0] > (*list).listb[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i != (*list).s1 && (*list).lista[i] != lo)
	{
		if ((*list).lista[0] > (*list).lista[i])
			return (-1);
		i++;
	}
	rotate_a(list, 1);
	return (0);
}

void	rotate_or_not(t_list *list)
{
	int i;
	int lo;

	i = 0;
	lo = get_lo_value((*list).lista, (*list).s1);
	while (i != (*list).s2)
	{
		if (lo > (*list).listb[i])
			lo = (*list).listb[i];
		i++;
	}
	if (check_list_sort(*list) == 0)
		return ;
	if ((*list).lista[0] == get_hi_value((*list).lista, (*list).s1))
		return ;
	while (1)
	{
		i = 0;
		i = last_nb_listb(list, lo);
		i += first_nb_listb(list, lo);
		i += first_nb_lista(list, lo);
		if (i == -3)
			return ;
	}
}

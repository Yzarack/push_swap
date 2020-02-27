/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:53:24 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 19:46:01 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_sort_pivot(int *lista, int s1, int pivot, int status)
{
	int i;
	int lo;

	i = 0;
	lo = get_lo_value(lista, s1);
	while (i < s1)
	{
		if (status == 1 && lista[i] == lo)
			return (1);
		if (lista[i] < pivot)
			return (-1);
		i++;
	}
	return (1);
}

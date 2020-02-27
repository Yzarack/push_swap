/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_listb_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:23:59 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/05 00:26:56 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		one_listb_sort(int *list, int size)
{
	int i;
	int hi;

	i = 0;
	if (size == 0)
		return (1);
	hi = get_hi_value(list, size);
	while (list[i] != hi)
		i++;
	if (i != size - 1)
		i++;
	else
		i = 0;
	while (list[i] != hi)
	{
		if (i != 0 && list[i] > list[i - 1])
			return (-1);
		else if (i == 0 && list[i] > list[size - 1])
			return (-1);
		if (i != size - 1)
			i++;
		else
			i = 0;
	}
	return (1);
}

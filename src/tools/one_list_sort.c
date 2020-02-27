/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_list_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:38:56 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 19:49:57 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		one_list_sort(int *list, int size)
{
	int i;
	int lo;

	i = 0;
	lo = get_lo_value(list, size);
	while (list[i] != lo)
		i++;
	if (i != size - 1)
		i++;
	else
		i = 0;
	while (list[i] != lo)
	{
		if (i != 0 && list[i] < list[i - 1])
			return (-1);
		else if (i == 0 && list[i] < list[size - 1])
			return (-1);
		if (i != size - 1)
			i++;
		else
			i = 0;
	}
	return (1);
}

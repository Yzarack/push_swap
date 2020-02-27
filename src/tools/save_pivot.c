/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:01:51 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/05 05:09:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		save_pivot(t_pivot *pivot)
{
	int *dup;

	if ((*pivot).size == 0)
		(*pivot).size = 1;
	if ((*pivot).size == -1)
	{
		if (!((*pivot).tab_pivot = (int *)malloc(sizeof(int) * 1)))
			return (-1);
		(*pivot).size = 1;
	}
	else
	{
		if (!(dup = (int *)malloc(sizeof(int) * (*pivot).size)))
			return (-1);
		dup = ft_memcpy_push(dup, (*pivot).tab_pivot, (*pivot).size);
		free((*pivot).tab_pivot);
		(*pivot).size += 1;
		if (!((*pivot).tab_pivot = (int *)malloc(sizeof(int) * (*pivot).size)))
			return (-1);
		(*pivot).tab_pivot = ft_memcpy_push((*pivot).tab_pivot,
		dup, (*pivot).size - 1);
		free(dup);
	}
	(*pivot).tab_pivot[(*pivot).size - 1] = (*pivot).pivot;
	return (0);
}

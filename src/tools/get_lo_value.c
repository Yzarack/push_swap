/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lo_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:34:15 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:56:57 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lo_value(int *list, int size)
{
	int lo;
	int i;

	lo = list[0];
	i = 0;
	while (i != size)
	{
		if (lo > list[i])
			lo = list[i];
		i++;
	}
	return (lo);
}

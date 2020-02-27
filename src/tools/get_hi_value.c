/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hi_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:57:35 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:56:40 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_hi_value(int *list, int size)
{
	int hi;
	int i;

	hi = list[0];
	i = 0;
	while (i != size)
	{
		if (hi < list[i])
			hi = list[i];
		i++;
	}
	return (hi);
}

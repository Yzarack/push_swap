/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:44:14 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/04 21:49:06 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_pivot(int *tab, int size, float divide)
{
	int hi;
	int lo;
	int mi;
	int i;

	i = 0;
	hi = get_hi_value(tab, size);
	lo = get_lo_value(tab, size);
	mi = (lo + hi) / divide;
	if (mi >= hi || mi <= lo)
		mi = (lo + hi) / 2;
	return (mi);
}

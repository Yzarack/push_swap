/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ucount_min_preci.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:54:41 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/03 09:24:10 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ucount_min_preci(unsigned long long nb, int base)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

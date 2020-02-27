/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_min_preci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:07:36 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/04 09:48:16 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_min_preci(long long nb, int base)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb == LLONG_MIN)
		return (20);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

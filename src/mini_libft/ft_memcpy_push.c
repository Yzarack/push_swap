/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:56:05 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/19 13:29:04 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy_push(void *dest, const void *src, size_t n)
{
	size_t		i;
	int			*tab1;
	int			*tab2;

	tab1 = (int *)src;
	tab2 = (int *)dest;
	i = 0;
	while (i < n)
	{
		tab2[i] = tab1[i];
		i++;
	}
	return (dest);
}

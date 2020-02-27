/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:42:29 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:40:31 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_b(t_list *list, int print)
{
	int		*dup;
	int		save;

	save = 0;
	if ((*list).s2 < 2)
		return (-1);
	if (print == 1)
		ft_printf("rb\n");
	if (!(dup = (int *)malloc(sizeof(int) * (*list).s2)))
		return (-2);
	dup = ft_memcpy_push(dup, (*list).listb, (*list).s2);
	(*list).listb[(*list).s2 - 1] = dup[0];
	while (save + 1 != (*list).s2)
	{
		(*list).listb[save] = dup[save + 1];
		save++;
	}
	free(dup);
	return (0);
}

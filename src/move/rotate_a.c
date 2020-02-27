/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:43:39 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:43:58 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_list *list, int print)
{
	int		*dup;
	int		save;

	save = 0;
	if ((*list).s1 < 2)
		return (-1);
	if (print == 1)
		ft_printf("ra\n");
	if (!(dup = (int *)malloc(sizeof(int) * (*list).s1)))
		return (-2);
	dup = ft_memcpy_push(dup, (*list).lista, (*list).s1);
	(*list).lista[(*list).s1 - 1] = dup[0];
	while (save + 1 != (*list).s1)
	{
		(*list).lista[save] = dup[save + 1];
		save++;
	}
	free(dup);
	return (0);
}

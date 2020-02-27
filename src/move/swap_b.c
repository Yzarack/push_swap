/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:51:08 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/25 17:40:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list *list, int print)
{
	int save;

	if ((*list).s2 < 2)
		return ;
	if (print == 1)
		ft_printf("sb\n");
	save = (*list).listb[0];
	(*list).listb[0] = (*list).listb[1];
	(*list).listb[1] = save;
}

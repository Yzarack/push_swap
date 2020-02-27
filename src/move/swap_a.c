/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:50:11 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:52:25 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *list, int print)
{
	int save;

	if ((*list).s1 < 2)
		return ;
	if (print == 1)
		ft_printf("sa\n");
	save = (*list).lista[0];
	(*list).lista[0] = (*list).lista[1];
	(*list).lista[1] = save;
}

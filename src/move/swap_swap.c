/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:06 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:52:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_list *list, int print)
{
	if (print == 1)
		ft_printf("ss\n");
	swap_a(list, 0);
	swap_b(list, 0);
}

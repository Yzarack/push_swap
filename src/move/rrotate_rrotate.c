/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_rrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:44:04 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:50:46 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rrotate_rrotate(t_list *list)
{
	int		res;

	res = rrotate_a(list, 0);
	if (res == -2)
		return (res);
	res = rrotate_b(list, 0);
	return (res);
}

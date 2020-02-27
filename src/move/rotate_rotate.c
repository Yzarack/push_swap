/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:40:04 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:41:22 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_rotate(t_list *list)
{
	int res;

	res = rotate_a(list, 0);
	if (res == -2)
		return (res);
	res = rotate_b(list, 0);
	return (res);
}

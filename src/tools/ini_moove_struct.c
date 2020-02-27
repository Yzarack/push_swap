/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_moove_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:29:14 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 18:58:47 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ini_moove_struct(t_moove *moove, char list)
{
	if (!(*moove = (t_moove)malloc(sizeof(void *) * 2)))
		return (-1);
	if (list == 'a')
	{
		(*moove)[0] = &rotate_a;
		(*moove)[1] = &rrotate_a;
	}
	else
	{
		(*moove)[0] = &rotate_b;
		(*moove)[1] = &rrotate_b;
	}
	return (0);
}

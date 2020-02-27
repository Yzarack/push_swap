/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:01:19 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 20:47:51 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_index(t_list *list, int i, int val, char c)
{
	t_moove moove;
	int		res;
	int		m;

	m = 0;
	ini_moove_struct(&moove, c);
	if (c == 'a')
		res = (*list).s1 / 2;
	else
		res = (*list).s2 / 2;
	if (i > res)
		m = 1;
	if (c == 'a')
	{
		while ((*list).lista[0] != val)
			moove[m](list, 1);
	}
	else
	{
		while ((*list).listb[0] != val)
			moove[m](list, 1);
	}
	free(moove);
}

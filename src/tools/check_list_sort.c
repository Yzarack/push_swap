/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:20:45 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/07 23:34:19 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_list_sort(t_list list)
{
	int i;

	i = 0;
	if (list.s2 != 0)
		return (-1);
	while (i + 1 < list.s1)
	{
		if (list.lista[i] > list.lista[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

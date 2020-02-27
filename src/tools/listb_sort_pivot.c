/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listb_sort_pivot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 07:19:57 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 19:46:14 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		listb_sort_pivot(int *listb, int s2, int pivot)
{
	int i;

	i = 0;
	if (s2 == 0)
		return (1);
	while (i < s2)
	{
		if (listb[i] > pivot)
			return (-1);
		i++;
	}
	return (1);
}

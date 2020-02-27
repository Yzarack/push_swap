/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:02:21 by jthierce          #+#    #+#             */
/*   Updated: 2019/06/20 16:23:14 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_separate_nb(const char *str, int *i)
{
	int		j;
	int		nb;
	char	*snb;

	j = *i;
	while ((str[j] <= '9' && str[j] >= '0') || str[j] == '+')
		j++;
	if (j == 0)
		return (0);
	if (!(snb = (char *)malloc(sizeof(char) * (j - *i + 1))))
		return (-2);
	j = 0;
	while ((str[*i] <= '9' && str[*i] >= '0') || str[*i] == '+')
	{
		snb[j] = str[*i];
		(*i)++;
		j++;
	}
	snb[j] = '\0';
	nb = ft_atoi(snb);
	free(snb);
	return (nb);
}

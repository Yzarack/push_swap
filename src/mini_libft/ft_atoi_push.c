/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:13:36 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 23:27:18 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long			ft_space(const char *str, long i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	return (i);
}

long			ft_atoi_push(const char *str)
{
	long		i;
	long		result;
	long		div;

	i = ft_space(str, 0);
	result = 0;
	div = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] != '-' && str[i] != '+' && i != 0)
	{
		i--;
		if (str[i] != '-' && str[i] != '+')
			result += (div * (str[i] - '0'));
		div *= 10;
	}
	if (result > INT64_MAX)
		return (str[ft_space(str, 0)] == '-' ? 0 : -1);
	if (str[ft_space(str, 0)] == '-')
		return (result * -1);
	return (result);
}

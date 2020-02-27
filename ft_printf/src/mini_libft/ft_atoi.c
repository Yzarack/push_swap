/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:13:36 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 00:06:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_space(const char *str, long i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long long	i;
	size_t		result;
	size_t		div;

	i = ft_space(str, 0);
	result = 0;
	div = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i + 1] && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] != '-' && i - ft_space(str, 0) != -1 && str[i] != '+')
	{
		result = div * (str[i] - '0') + result;
		div *= 10;
		i--;
	}
	if (result > INT64_MAX)
		return (str[ft_space(str, 0)] == '-' ? 0 : -1);
	if (str[ft_space(str, 0)] == '-')
		return ((int)result * -1);
	return ((int)result);
}

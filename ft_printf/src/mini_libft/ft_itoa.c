/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:47:18 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/10 14:42:47 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_int_in_str_itoa(size_t n, char *str, size_t puis, int neg)
{
	size_t	i;

	i = 0;
	if (neg == -1)
	{
		str[i] = '-';
		i++;
	}
	while (puis != 0)
	{
		str[i] = (n / puis) + 48;
		n = n % puis;
		if (puis == 1)
			puis = 0;
		puis /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_intisneg(long n, size_t *save_n, long *length)
{
	if (n < 0)
	{
		*save_n = (size_t)n * -1;
		*length = *length + 1;
		return (-1);
	}
	return (1);
}

char		*ft_itoa(long n)
{
	long	length;
	size_t	puis;
	char	*str;
	int		neg;
	size_t	save_n;

	save_n = n;
	puis = 1;
	length = 1;
	neg = ft_intisneg(n, &save_n, &length);
	while ((puis * 10) <= save_n)
	{
		length++;
		puis *= 10;
	}
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str = ft_int_in_str_itoa(save_n, str, puis, neg);
	return (str);
}

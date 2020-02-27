/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:17:48 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/15 18:36:33 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_neg(char *str, int neg, t_flags options)
{
	if (neg == 1)
		str[0] = '-';
	else if (options.sign == 1)
		str[0] = '+';
	else if (options.space == 1)
		str[0] = ' ';
	return (str);
}

char	*ft_llongmin_itoa(char *str, int i, char *base, int nb_base)
{
	long long nb;

	nb = 922337203685477580;
	str[i] = base[8];
	while (i > 0)
	{
		i--;
		str[i] = base[nb % nb_base];
		nb /= nb_base;
	}
	str[0] = '-';
	return (str);
}

char	*ft_printf_itoa_place(long long nb, char *str, char *base,
		t_flags options)
{
	int	nb_base;

	nb_base = ft_strlen(base);
	while (options.preci > 0)
	{
		options.preci--;
		str[options.preci] = base[nb % nb_base];
		nb /= nb_base;
	}
	return (str);
}

char	*ft_printf_itoa_base(long long nb, char *base, t_flags options, char c)
{
	char	*str;
	int		nb_base;
	int		neg;

	neg = 0;
	nb_base = ft_strlen(base);
	if (nb < 0 && nb != LLONG_MIN)
	{
		neg = 1;
		nb *= -1;
	}
	if ((options.space == 1 && neg != 1) || (options.sign == 1 && neg != 1 &&
	options.zero != options.preci) || (options.sign == 1 && neg != 1 &&
	options.zero < options.preci && 1 != count_min_preci(nb, nb_base)) ||
	(count_min_preci(nb, nb_base) + options.sign > options.preci))
		options.preci++;
	if (!(str = (char *)malloc(sizeof(char) * (options.preci + 1))))
		return (NULL);
	ft_memset(str, c, options.preci);
	str[options.preci] = '\0';
	if (nb == LLONG_MIN)
		return (ft_llongmin_itoa(str, options.preci - 1, base, nb_base));
	str = ft_printf_itoa_place(nb, str, base, options);
	str = ft_itoa_base_neg(str, neg, options);
	return (str);
}

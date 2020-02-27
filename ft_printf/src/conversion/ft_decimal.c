/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:35:01 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/15 18:57:06 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_decimal_conver(void *nb, t_flags options)
{
	long long	inb;

	inb = (int)nb;
	if (options.ld_conver == 2)
		inb = (long long int)nb;
	else if (options.ld_conver == 1)
		inb = (long int)nb;
	else if (options.h_conver == 1)
		inb = (short int)nb;
	else if (options.h_conver == 2)
		inb = (signed char)nb;
	return (inb);
}

char		*ft_f_decimal(char *str, long long int inb, t_flags options)
{
	char *str2;

	str2 = ft_strdup(str);
	if (options.preci == 0 && inb == 0)
	{
		free(str);
		str = ft_strndup(str2, options.preci + options.sign);
	}
	free(str2);
	options.zero -= ft_strlen(str);
	if (options.preci != -1 && options.zero > 0)
		str = ft_zerowpreci(str, options);
	options.neg -= ft_strlen(str);
	if (options.neg > 0)
		str = ft_flags_neg(str, options);
	options.minimal_width -= ft_strlen(str);
	if (options.minimal_width > 0)
		str = ft_f_minwidth(str, options);
	return (str);
}

int			ft_decimal(void *nb, t_flags options)
{
	char		*str;
	long long	inb;
	int			spreci;

	inb = ft_decimal_conver(nb, options);
	spreci = options.preci;
	if (inb == 0 && spreci == 0 && options.space == 1 &&
		options.minimal_width == 0)
		options.minimal_width = 1;
	if (inb < 0)
		options.preci += 1;
	else if (spreci == -1)
		options.zero -= options.space;
	if (options.preci < count_min_preci(inb, 10))
		options.preci = count_min_preci(inb, 10);
	if (spreci == -1 && options.zero > count_min_preci(inb, 10))
		options.preci = options.zero;
	str = ft_printf_itoa_base(inb, "0123456789", options, '0');
	options.preci = spreci;
	str = ft_f_decimal(str, inb, options);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-2);
	free(str);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:26:28 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:21:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_udecimal_conver(void *nb, t_flags options)
{
	unsigned long long	inb;

	inb = (unsigned int)nb;
	if (options.ld_conver == 2)
		inb = (unsigned long long int)nb;
	else if (options.ld_conver == 1)
		inb = (unsigned long int)nb;
	else if (options.h_conver == 1)
		inb = (unsigned short int)nb;
	else if (options.h_conver == 2)
		inb = (unsigned char)nb;
	return (inb);
}

char				*ft_f_udecimal(char *str, t_flags options)
{
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

int					ft_udecimal(void *nb, t_flags options)
{
	char				*str;
	unsigned long long	inb;
	int					spreci;

	options.space = 0;
	options.sign = 0;
	spreci = options.preci;
	inb = ft_udecimal_conver(nb, options);
	if (options.preci < ucount_min_preci(inb, 10))
		options.preci = ucount_min_preci(inb, 10);
	if (spreci == 0 && inb == 0)
		options.preci = 0;
	if (spreci == -1 && options.zero > ucount_min_preci(inb, 10))
		options.preci = options.zero;
	str = ft_printf_utoa_base(inb, "0123456789", options, '0');
	options.preci = spreci;
	str = ft_f_udecimal(str, options);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-2);
	free(str);
	return (1);
}

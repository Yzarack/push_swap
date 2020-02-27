/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:54:23 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:19:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_octal_conver(void *nb, t_flags options)
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

char				*ft_octal_flags(char *str, t_flags options, int spreci)
{
	char	*buff;

	if (str == NULL)
		return (NULL);
	if (options.special_print == 1)
	{
		buff = ft_strdup(str);
		free(str);
		str = ft_strjoin("0", buff);
		free(buff);
	}
	options.zero -= ft_strlen(str);
	if (spreci != -1 && options.zero > 0)
		str = ft_zerowpreci(str, options);
	options.neg -= ft_strlen(str);
	if (options.neg > 0)
		str = ft_flags_neg(str, options);
	options.minimal_width -= ft_strlen(str);
	if (options.minimal_width > 0)
		str = ft_f_minwidth(str, options);
	return (str);
}

int					ft_octal(void *nb, t_flags options)
{
	char				*str;
	int					spreci;
	unsigned long long	inb;

	options.sign = 0;
	options.space = 0;
	inb = ft_octal_conver(nb, options);
	spreci = options.preci;
	if (options.preci < ucount_min_preci(inb, 8))
		options.preci = ucount_min_preci(inb, 8);
	if (spreci == 0 && inb == 0 && options.special_print != 1)
		options.preci = 0;
	if (spreci == -1 && options.zero > ucount_min_preci(inb, 8))
		options.preci = options.zero;
	if (inb == 0)
		options.special_print = 0;
	if (options.special_print == 1 && options.preci != ucount_min_preci(inb, 8))
		options.preci -= 1;
	str = ft_printf_utoa_base(inb, "01234567", options, '0');
	str = ft_octal_flags(str, options, spreci);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-1);
	free(str);
	return (1);
}

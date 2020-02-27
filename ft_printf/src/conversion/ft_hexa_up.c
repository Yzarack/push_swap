/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:21:48 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:19:14 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_hexau_conver(void *nb, t_flags options)
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

char				*ft_hexau_flags(char *str, t_flags options, int spreci,
					unsigned long long nb)
{
	char	*buff;

	if (str == NULL)
		return (NULL);
	if (options.special_print == 1 && nb != 0)
	{
		buff = ft_strdup(str);
		free(str);
		str = ft_strjoin("0X", buff);
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

int					ft_hexau_speprint(t_flags options, unsigned long long inb)
{
	options.preci = options.zero;
	if (options.special_print == 1 && options.preci
	> ucount_min_preci(inb, 16) + 1)
		options.preci -= 2;
	else if (options.special_print == 1 && options.preci
	>= ucount_min_preci(inb, 16) + 1)
		options.preci -= 1;
	return (options.preci);
}

int					ft_hexa_up(void *nb, t_flags options)
{
	char				*str;
	int					spreci;
	unsigned long long	inb;

	options.sign = 0;
	options.space = 0;
	inb = ft_hexau_conver(nb, options);
	spreci = options.preci;
	if (options.preci < ucount_min_preci(inb, 16))
		options.preci = ucount_min_preci(inb, 16);
	if (spreci == 0 && inb == 0)
		options.preci = 0;
	if (spreci == -1 && options.zero > ucount_min_preci(inb, 16))
		options.preci = ft_hexau_speprint(options, inb);
	str = ft_printf_utoa_base(inb, "0123456789ABCDEF", options, '0');
	str = ft_hexau_flags(str, options, spreci, inb);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-2);
	free(str);
	return (0);
}

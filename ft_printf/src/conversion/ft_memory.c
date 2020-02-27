/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:05:53 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:19:23 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f_memory(char *str, t_flags options)
{
	char	*dup;

	dup = ft_strjoin("0x", str);
	free(str);
	options.neg -= ft_strlen(dup);
	if (options.neg > 0)
		dup = ft_flags_neg(dup, options);
	options.minimal_width -= ft_strlen(dup);
	if (options.minimal_width > 0)
		dup = ft_f_minwidth(dup, options);
	return (dup);
}

int		ft_memory(void *nb, t_flags options)
{
	char	*str;
	long	memory;
	int		spreci;

	options.space = 0;
	options.sign = 0;
	options.zero = -1;
	spreci = options.preci;
	memory = (long)nb;
	if (spreci == -1)
		options.preci = ucount_min_preci((long)memory, 16);
	if (options.minimal_width - 2 > options.preci)
		options.preci = ucount_min_preci((long)memory, 16);
	if (spreci != 0)
		str = ft_printf_itoa_base((long)memory, "0123456789abcdef",
		options, '0');
	else
		str = ft_strdup("");
	str = ft_f_memory(str, options);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-1);
	free(str);
	return (0);
}

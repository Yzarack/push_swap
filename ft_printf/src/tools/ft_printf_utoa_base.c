/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:00:14 by jthierce          #+#    #+#             */
/*   Updated: 2019/06/15 13:04:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_utoa_base(unsigned long long nb, char *base,
		t_flags options, char c)
{
	char	*str;
	int		nb_base;

	nb_base = ft_strlen(base);
	if (options.space == 1 || options.sign == 1)
		options.preci++;
	if (!(str = (char *)malloc(sizeof(char) * (options.preci + 1))))
		return (NULL);
	ft_memset(str, c, options.preci);
	str[options.preci] = '\0';
	while (options.preci > 0)
	{
		options.preci--;
		str[options.preci] = base[nb % nb_base];
		nb /= nb_base;
	}
	if (options.sign == 1)
		str[0] = '+';
	else if (options.space == 1)
		str[0] = ' ';
	return (str);
}

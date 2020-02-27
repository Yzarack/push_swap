/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:44:15 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:18:04 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(void *str, t_flags options)
{
	char	c;
	char	*buff;
	int		c_null;

	c_null = 0;
	c = (char)str;
	if (c == 0)
		c_null = 1;
	if (!(buff = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	buff[0] = c;
	buff[1] = '\0';
	options.neg -= 1;
	if (options.neg > 0)
		buff = ft_flags_neg(buff, options);
	options.minimal_width = options.minimal_width - (ft_strlen(buff) + c_null);
	if (options.minimal_width > 0)
		buff = ft_f_minwidth(buff, options);
	if (ft_printf_save(buff, ft_strlen(buff) + c_null, 0) == -2)
		return (-2);
	free(buff);
	return (1);
}

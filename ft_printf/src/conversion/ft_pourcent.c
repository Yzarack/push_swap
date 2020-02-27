/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:49:32 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:19:36 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent(t_flags options)
{
	char *buff;

	if (!(buff = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	buff[0] = '%';
	buff[1] = '\0';
	options.neg -= 1;
	if (options.neg > 0)
		buff = ft_flags_neg(buff, options);
	options.minimal_width -= ft_strlen(buff);
	if (options.minimal_width > 0)
		buff = ft_f_minwidth(buff, options);
	if (ft_printf_save(buff, ft_strlen(buff), 0) == -2)
		return (-2);
	free(buff);
	return (1);
}

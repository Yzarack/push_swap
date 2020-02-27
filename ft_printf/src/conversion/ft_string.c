/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:28:59 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 12:11:05 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f_string(char *str, char *dup, t_flags options)
{
	if (str == NULL && options.preci >= 6)
		options.neg -= 6;
	else
		options.neg -= ft_strlen(dup);
	if (options.neg > 0)
		dup = ft_flags_neg(dup, options);
	options.minimal_width -= ft_strlen(dup);
	if (options.minimal_width > 0)
		dup = ft_f_minwidth(dup, options);
	return (dup);
}

int		ft_string(void *str, t_flags options)
{
	char	*dup;
	int		spreci;

	spreci = options.preci;
	if (spreci == -1)
	{
		options.preci = ft_strlen(str);
		if (str == NULL)
			options.preci = 6;
	}
	dup = ft_strndup(str, options.preci);
	dup = ft_f_string(str, dup, options);
	options.preci = ft_strlen(dup);
	if (dup == NULL && spreci != 0)
		options.preci = 6;
	if (ft_printf_save(dup, options.preci, 0) == -2)
		return (-2);
	free(dup);
	return (1);
}

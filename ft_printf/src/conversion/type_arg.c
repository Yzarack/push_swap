/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:37:49 by jthierce          #+#    #+#             */
/*   Updated: 2019/06/18 08:36:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_type_arg(t_type *type)
{
	if (!(*type = (t_type)malloc(sizeof(void *) * 256)))
		return (-1);
	(*type)['p'] = &ft_memory;
	(*type)['c'] = &ft_char;
	(*type)['s'] = &ft_string;
	(*type)['d'] = &ft_decimal;
	(*type)['i'] = &ft_decimal;
	(*type)['o'] = &ft_octal;
	(*type)['x'] = &ft_hexa_down;
	(*type)['X'] = &ft_hexa_up;
	(*type)['u'] = &ft_udecimal;
	return (0);
}

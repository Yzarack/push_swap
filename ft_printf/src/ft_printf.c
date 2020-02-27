/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:27:27 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/15 15:22:56 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags_verif(t_flags fl)
{
	if (fl.neg == -2 || fl.zero == -2 || fl.preci == -2 ||
	fl.minimal_width == -2)
		return (-1);
	return (0);
}

int		ft_printf_arg(const char *format, va_list ap, int *i, t_type type)
{
	t_flags	options;
	int		v_result;

	v_result = 0;
	(*i)++;
	options = ft_printf_pars(format, i);
	if (ft_flags_verif(options) != 0)
		return (-1);
	if (format[*i] == 'f' && options.lu_conver == 1)
		v_result = ft_float(va_arg(ap, long double), options);
	else if (format[*i] == 'f' && options.ld_conver == 1)
		v_result = ft_float(va_arg(ap, double), options);
	else if (format[*i] == 'f')
		v_result = ft_float(va_arg(ap, double), options);
	else if (format[*i] == '%')
		v_result = ft_pourcent(options);
	else
		v_result = (*type[(int)format[*i]])(va_arg(ap, void *), options);
	return (v_result);
}

int		ft_printf_print(const char *format, va_list ap, t_type type)
{
	int	i;
	int result;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((result = ft_printf_arg(format, ap, &i, type)) == -1)
			{
				free(type);
				return (ft_printf_save(NULL, 0, -1));
			}
			if (result == -2)
			{
				free(type);
				return (-2);
			}
		}
		else
			ft_printf_save(format + i, 1, 0);
		i++;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;
	t_type	type;

	if (format == NULL || format[0] == 0)
		return (0);
	va_start(ap, format);
	if (ft_type_arg(&type) == -1)
		return (-1);
	if ((result = ft_printf_print(format, ap, type)) == -1)
		return (0);
	if (result == -2)
		return (-1);
	free(type);
	va_end(ap);
	return (ft_printf_save(NULL, 0, 1));
}

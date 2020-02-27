/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:16:30 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/04 17:01:55 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_pars(const char *str, t_flags *flags, int *i)
{
	while (str[(*i)] == 'h')
	{
		(*i)++;
		(*flags).h_conver++;
	}
	while (str[(*i)] == 'l')
	{
		(*i)++;
		(*flags).ld_conver++;
	}
	while (str[(*i)] == 'L')
	{
		(*i)++;
		(*flags).lu_conver++;
	}
	while (str[(*i)] == '#')
	{
		(*i)++;
		(*flags).special_print = 1;
	}
	flags_pars_nb(str, flags, i);
}

t_flags	ft_iniflags(void)
{
	t_flags	ini;

	ini.special_print = 0;
	ini.zero = 0;
	ini.neg = 0;
	ini.sign = 0;
	ini.space = 0;
	ini.minimal_width = 0;
	ini.preci = -1;
	ini.ld_conver = 0;
	ini.lu_conver = 0;
	ini.h_conver = 0;
	return (ini);
}

int		ft_pars_error(const char *str, int *i, t_flags *flags)
{
	if ((str[*i] != '#' && str[*i] != ' ' && str[*i] != '+' && str[*i] != '-'
		&& str[*i] != '.' && str[*i] != 'd' && str[*i] != 'i' && str[*i] != 'o'
		&& str[*i] != 'u' && str[*i] != 'x' && str[*i] != 'X' && str[*i] != 'p'
		&& str[*i] != 'c' && str[*i] != 's' && str[*i] != 'f' && str[*i] &&
		str[*i] != 'l' && str[*i] != 'L' && str[*i] != 'h' && str[*i] != '%') ||
		str[*i] == 0)
	{
		(*flags).preci = -2;
		return (-1);
	}
	return (0);
}

t_flags	ft_printf_pars(const char *str, int *i)
{
	t_flags flags;

	flags = ft_iniflags();
	if (!(str[*i]))
		flags.preci = -2;
	while (str[*i] != 'd' && str[*i] != 'i' && str[*i] != 'o' && str[*i] != 'u'
	&& str[*i] != 'x' && str[*i] != 'X' && str[*i] != 'p' && str[*i] != 'c'
	&& str[*i] != 's' && str[*i] != 'f' && str[*i] != '%' && str[*i])
	{
		while (str[(*i)] == '+')
		{
			(*i)++;
			flags.sign = 1;
		}
		while (str[(*i)] == ' ')
		{
			(*i)++;
			flags.space = 1;
		}
		flags_pars(str, &flags, i);
		if (ft_pars_error(str, i, &flags) == -1)
			return (flags);
	}
	return (flags);
}

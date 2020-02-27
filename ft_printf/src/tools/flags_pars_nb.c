/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pars_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:28:57 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/04 13:47:25 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_neg_pars(const char *str, t_flags *flags, int *i)
{
	while (str[(*i)] == '-')
		(*i)++;
	while (str[(*i)] == '+' || str[(*i)] == '#' || str[(*i)] == ' ')
	{
		if (str[(*i)] == '+')
		{
			(*flags).sign = 1;
			(*i)++;
		}
		if (str[(*i)] == '#')
		{
			(*flags).special_print = 1;
			(*i)++;
		}
		if (str[(*i)] == ' ')
		{
			(*flags).space = 1;
			(*i)++;
		}
	}
	(*flags).neg = ft_separate_nb(str, i);
}

void	flags_zero_pars(const char *str, t_flags *flags, int *i)
{
	while (str[(*i)] == '0')
		(*i)++;
	while (str[(*i)] == '+' || str[(*i)] == '#' || str[(*i)] == ' ')
	{
		if (str[(*i)] == '+')
		{
			(*flags).sign = 1;
			(*i)++;
		}
		if (str[(*i)] == '#')
		{
			(*flags).special_print = 1;
			(*i)++;
		}
		if (str[(*i)] == ' ')
		{
			(*flags).space = 1;
			(*i)++;
		}
	}
	(*flags).zero = ft_separate_nb(str, i);
}

void	flags_pars_nb(const char *str, t_flags *flags, int *i)
{
	if (str[(*i)] == '-')
		flags_neg_pars(str, flags, i);
	if (str[(*i)] == '0')
		flags_zero_pars(str, flags, i);
	if (str[(*i)] == '.')
	{
		(*i)++;
		(*flags).preci = ft_separate_nb(str, i);
	}
	if (str[(*i)] <= '9' && str[(*i)] >= '0')
		(*flags).minimal_width = ft_separate_nb(str, i);
}

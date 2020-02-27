/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:42:52 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/15 19:33:51 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_float_zero_sign(char **str)
{
	int		neg;

	neg = 0;
	if ((*str) == NULL)
		return (neg);
	if ((*str)[0] == '-')
	{
		neg = 1;
		(*str)[0] = '0';
	}
	if ((*str)[0] == '+')
	{
		neg = 2;
		(*str)[0] = '0';
	}
	return (neg);
}

char		*ft_float_zero(char *str, t_flags options)
{
	char	*buff;
	char	*str2;
	int		neg;

	neg = ft_float_zero_sign(&str);
	if (!(buff = (char *)malloc(sizeof(char) * (options.zero + 1))))
		return (NULL);
	buff[options.zero] = '\0';
	ft_memset(buff, '0', options.zero);
	str2 = ft_strjoinfree(buff, str);
	if (neg == 1)
		str2[0] = '-';
	if (neg == 2)
		str2[0] = '+';
	free(str);
	return (str2);
}

int			ft_roundmax(long double nb)
{
	long double i;

	i = 0.1;
	if (nb < 0)
		nb *= -1;
	nb -= ((long long int)(nb / 1));
	if ((int)(nb / i) < 5)
		return (0);
	return (1);
}

long double	ft_round(long double nb, t_flags options)
{
	long long int	save;
	int				preci;
	long double		i;

	i = 0;
	preci = 6;
	if (options.preci != -1)
		preci = options.preci;
	save = ((long long int)(nb / 1));
	if (nb > 0)
		nb = (nb - save) + 1;
	else if (nb < 0)
		nb = (nb - save) - 1;
	while (i++ != preci)
		nb *= 10;
	if (ft_roundmax(nb) == 1)
	{
		if (nb < 0)
			nb--;
		else
			nb++;
	}
	while (--i != 0)
		nb /= 10;
	return ((save + nb) < 0 ? save + nb + 1 : save + nb - 1);
}

int			ft_float(long double nb, t_flags options)
{
	char		*str;
	long double	nb_round;

	nb_round = ft_round(nb, options);
	if (nb == 0)
		nb_round = 0;
	str = ft_float_itoa(nb_round, options);
	options.zero = options.zero - ft_strlen(str) - options.space;
	if (options.zero > 0)
		str = ft_float_zero(str, options);
	options.neg = options.neg - ft_strlen(str) - options.space;
	if (options.neg > 0)
		str = ft_flags_neg(str, options);
	if (nb >= 0)
		str = ft_f_space(str, options);
	options.minimal_width -= ft_strlen(str);
	if (options.minimal_width > 0)
		str = ft_f_minwidth(str, options);
	if (ft_printf_save(str, ft_strlen(str), 0) == -2)
		return (-2);
	free(str);
	return (0);
}

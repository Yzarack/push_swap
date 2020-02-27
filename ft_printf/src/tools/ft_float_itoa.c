/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:38:12 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/10 17:45:25 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float_sign(char *str)
{
	char *buff;

	buff = ft_strjoin("+", str);
	free(str);
	return (buff);
}

char	*float_nb_zero(char *str, int preci)
{
	char *buff;
	char *str2;

	if (!(buff = malloc(sizeof(char) * (preci + 1))))
		return (NULL);
	buff[preci] = '\0';
	while (preci != 0)
	{
		preci--;
		buff[preci] = '0';
	}
	str2 = ft_strjoinfree(str, buff);
	free(buff);
	return (str2);
}

char	*ft_f_itoa(long double nb, t_flags options)
{
	char	*str;
	char	*str2;

	if ((str = ft_itoa((long long int)(nb / 1))) == NULL)
		return (NULL);
	if ((long long int)(nb / 1) == 0 && nb < 0)
	{
		str2 = ft_strjoin("-", str);
		free(str);
		return (str2);
	}
	if (options.sign == 1 && nb >= 0)
		str = ft_float_sign(str);
	return (str);
}

char	*ft_f_itoareturn(char *str, char *str2, long double nb)
{
	char *buff;

	if (str2 == NULL || (str = ft_itoaspefloat((long)nb / 1)) == NULL)
		return (NULL);
	buff = ft_strjoinfree(str2, str);
	free(str);
	return (buff);
}

char	*ft_float_itoa(long double nb, t_flags options)
{
	char			*str;
	char			*str2;
	long double		i;

	i = 0;
	if (nb == 1.0 / 0.0 || nb == 1.0 / 0.0)
		return (ft_fiota_nbspe(nb));
	if (options.preci == -1)
		options.preci = 6;
	if ((str = ft_f_itoa(nb, options)) == NULL)
		return (NULL);
	if (nb != 0)
		nb = nb - (long long int)(nb / 1) + (nb > 0 ? 1 : -1);
	if (nb < 0)
		nb *= -1;
	if (options.preci == 0 && options.special_print == 0)
		return (str);
	str2 = ft_strjoinfree(str, ".");
	if (nb == 0)
		return (float_nb_zero(str2, options.preci));
	if (options.preci == 0)
		return (str2);
	while (i++ != options.preci)
		nb *= 10;
	return (ft_f_itoareturn(str, str2, nb));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 07:49:31 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/10 17:16:37 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags_neg(char *str, t_flags options)
{
	char	*buff;
	char	*str2;

	if (str == NULL)
		return (NULL);
	if (!(buff = (char *)malloc(sizeof(char) * (options.neg + 1))))
		return (NULL);
	buff[options.neg] = '\0';
	ft_memset(buff, ' ', options.neg);
	str2 = ft_strjoinfree(str, buff);
	free(buff);
	return (str2);
}

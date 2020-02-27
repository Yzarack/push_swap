/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerowpreci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:57:27 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/10 17:16:22 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zerowpreci(char *str, t_flags options)
{
	char	*buff;
	char	*str2;

	if (str == NULL)
		return (NULL);
	if (!(buff = (char *)malloc(sizeof(char) * (options.zero + 1))))
		return (NULL);
	buff[options.zero] = '\0';
	ft_memset(buff, ' ', options.zero);
	str2 = ft_strjoinfree(buff, str);
	free(str);
	return (str2);
}

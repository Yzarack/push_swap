/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_minwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:04:49 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/10 17:13:24 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f_minwidth(char *str, t_flags options)
{
	char	*buff;
	char	*str2;

	if (str == NULL)
		str = ft_strdup("(null)");
	if (!(buff = (char *)malloc(sizeof(char) * (options.minimal_width + 1))))
		return (NULL);
	buff[options.minimal_width] = '\0';
	ft_memset(buff, ' ', options.minimal_width);
	str2 = ft_strjoinfree(buff, str);
	free(str);
	return (str2);
}

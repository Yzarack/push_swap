/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:47:43 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 12:45:07 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *str, size_t n)
{
	char	*new;

	if (str == NULL)
		return (ft_strndup("(null)", n));
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	new[n] = '\0';
	while (n != 0)
	{
		n--;
		new[n] = str[n];
	}
	return (new);
}

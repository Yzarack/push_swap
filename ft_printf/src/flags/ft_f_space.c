/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:30:12 by jthierce          #+#    #+#             */
/*   Updated: 2019/06/25 16:33:12 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f_space(char *str, t_flags options)
{
	char	*buff;

	if (options.space == 1)
	{
		buff = ft_strjoin(" ", str);
		free(str);
		return (buff);
	}
	return (str);
}

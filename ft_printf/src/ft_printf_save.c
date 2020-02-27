/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:53:01 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/05 11:15:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfs_error(char **save)
{
	if ((*save) != NULL)
	{
		free((*save));
		(*save) = NULL;
	}
	return (-1);
}

int	ft_printfs_finish(char **save, int *len)
{
	putstr_printf((*save), *len);
	if ((*save) != NULL)
	{
		free((*save));
		(*save) = NULL;
	}
	return (*len);
}

int	ft_printf_save(const char *str, int n, int print)
{
	static	char	*save = NULL;
	static	int		len;

	if (print == -1)
		return (ft_printfs_error(&save));
	if (print == 1)
		return (ft_printfs_finish(&save, &len));
	if (save == NULL)
	{
		if (!(save = (char *)malloc(sizeof(char) * 4096)))
			return (-2);
		len = 0;
		ft_bzero(save, 4096);
	}
	if (str == NULL)
	{
		free(save);
		return (-2);
	}
	strncat_printf(save, str, n, len);
	len += n;
	return (1);
}

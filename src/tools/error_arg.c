/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:32:53 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 00:55:57 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error_arg_part(char **argv, int *i, int j)
{
	int save;

	save = 0;
	if (argv == NULL || ft_strlen(argv[*i]) == 0)
		return (-1);
	while (argv[*i][j])
	{
		save = j;
		while (argv[*i][j] == ' ')
			j++;
		if ((argv[*i][j] == '-' || argv[*i][j] == '+') && argv[*i][j] != 0
			&& save == 0)
			j++;
		if (((argv[*i][j] > '9' || argv[*i][j] < '0') && argv[*i][j] != 0) ||
		(save == 0 && argv[*i][j] == '\0'))
			return (-1);
		if (argv[*i][j] != 0)
			j++;
	}
	j = 0;
	if (ft_atoi_push(argv[*i]) > INT_MAX ||
	ft_atoi_push(argv[*i]) < INT_MIN)
		return (-1);
	*i += 1;
	return (0);
}

int		error_arg(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (error_arg_part(argv, &i, 0) == -1)
			return (-1);
	}
	return (0);
}

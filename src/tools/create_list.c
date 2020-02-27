/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:26:57 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 00:47:33 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char ***tab, int argc)
{
	int i;

	i = 0;
	while (i != argc)
	{
		free((*tab)[i]);
		i++;
	}
	free((*tab));
}

int		nb_double(t_list *list, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j + 1 < size)
		{
			j++;
			if ((*list).lista[i] == (*list).lista[j])
			{
				free((*list).lista);
				return (-1);
			}
		}
		i++;
		j = i;
	}
	return (0);
}

int		init_list(int *argc, char ***argv, t_list *list)
{
	if (*argc == 2)
	{
		if (((*argv) = ft_strsplit((*argv)[1], ' ', argc)) == NULL)
			return (-1);
	}
	(*list).s1 = *argc - 1;
	if (error_arg(*argc, *argv) == -1 || ft_strlen((*argv)[1]) == 0)
	{
		if ((*argv)[0] == NULL)
			free_tab(argv, *argc);
		return (-1);
	}
	if (!((*list).lista = (int *)malloc(sizeof(int) * (*argc - 1))))
		return (-1);
	if (!((*list).listb = (int *)malloc(sizeof(int) * (*argc - 1))))
	{
		free((*list).lista);
		return (-1);
	}
	return (0);
}

int		create_list(int argc, char **argv, t_list *list)
{
	int	i;

	i = 0;
	if (init_list(&argc, &argv, list) == -1)
		return (-1);
	ft_bzero((*list).lista, argc - 1);
	ft_bzero((*list).listb, argc - 1);
	while (i != argc - 1)
	{
		(*list).lista[i] = ft_atoi_push(argv[i + 1]);
		i++;
	}
	if (argv[0] == NULL)
		free_tab(&argv, argc);
	if (nb_double(list, argc - 1) == -1)
	{
		free((*list).listb);
		return (-1);
	}
	return (0);
}

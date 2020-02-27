/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:19:26 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 00:06:39 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_moove(t_list *list, char *line, int ret)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(list, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(list, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ret = push_a(list, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ret = push_b(list, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ret = rotate_a(list, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ret = rotate_b(list, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ret = rotate_rotate(list);
	else if (ft_strcmp(line, "rra") == 0)
		ret = rrotate_a(list, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ret = rrotate_b(list, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ret = rrotate_rrotate(list);
	else if (ft_strcmp(line, "ss") == 0)
		swap_swap(list, 0);
	else
		return (-2);
	return (ret);
}

int		read_instruction(t_list *list, int *count)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	while (ret != 2 && (ret = get_next_line(0, &line)) == 1)
	{
		if ((ret = check_moove(list, line, 0)) == -2)
		{
			free(line);
			return (-2);
		}
		free(line);
		(*count)++;
	}
	if (ret == -1)
		return (-2);
	return (0);
}

int		checker(int argc, char **argv)
{
	t_list	list;
	int		count;

	count = 0;
	list.s2 = 0;
	list.s1 = argc - 1;
	if (create_list(argc, argv, &list) == -1)
		return (-2);
	if (read_instruction(&list, &count) == -2)
	{
		free(list.lista);
		free(list.listb);
		return (-2);
	}
	count = check_list_sort(list);
	free(list.lista);
	free(list.listb);
	return (count);
}

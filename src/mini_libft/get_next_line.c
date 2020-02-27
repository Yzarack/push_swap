/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:26 by marvin            #+#    #+#             */
/*   Updated: 2019/08/01 00:08:20 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int		ft_read_in_char(char **line, char **save, int value, char *tmp)
{
	if (*save != NULL && *save[0] == '\0')
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	if (value == -1 && *save != NULL && *save[0] != '\0')
	{
		*line = ft_strdup("error");
		free(*save);
		*save = NULL;
		return (1);
	}
	else if (ft_strchrint(*save, '\n') != -1)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (value + 1))))
			return (-1);
		ft_bzero(*line, value + 1);
		*line = ft_strncat(*line, *save, value);
		tmp = *save;
		*save = ft_strdup(ft_strchr(*save, '\n'));
		free(tmp);
		*save = ft_strcpy(*save, *save + 1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	int			ret;
	char		*buff;
	char		*tmp;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (save == NULL)
		save = ft_strdup("");
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (ret != 0 && ft_strchrint(save, '\n') == -1)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	ret = ft_strchrint(save, '\n');
	return (ft_read_in_char(line, &save, ret, tmp));
}

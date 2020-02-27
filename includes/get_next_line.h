/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:23 by marvin            #+#    #+#             */
/*   Updated: 2019/07/23 19:31:33 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 10

int		get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:04:47 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/09 00:17:34 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef	struct	s_list{
	int		*lista;
	int		*listb;
	int		s1;
	int		s2;
}				t_list;

typedef	struct	s_pivot{
	int		*tab_pivot;
	long	pivot;
	int		size;
}				t_pivot;

typedef	int		(**t_moove)(t_list *list, int print);
int				ini_moove_struct(t_moove *moove, char list);
int				push_swap(int argc, char **argv);
int				checker(int argc, char **argv);
int				push_a(t_list *list, int print);
int				push_b(t_list *list, int print);
void			swap_swap(t_list *list, int print);
void			swap_b(t_list *list, int print);
void			swap_a(t_list *list, int print);
int				rotate_a(t_list *list, int print);
int				rotate_b(t_list *list, int print);
int				rotate_rotate(t_list *list);
int				rrotate_a(t_list *list, int print);
int				rrotate_b(t_list *list, int print);
int				rrotate_rrotate(t_list *list);
void			rotate_or_not(t_list *list);
int				error_arg(int argc, char **argv);
int				quicksort_part_three(t_list *list, t_pivot *pivot);
int				quicksort_part_two(t_list *list, t_pivot *pivot);
int				insertion_sort(t_list *list, int status);
int				insertion_sortlistb(t_list *list);
int				choose_pivot(int *tab, int size, float divide);
int				place_of_pivot(int *lista, int pivot);
int				save_pivot(t_pivot *pivot);
int				create_list(int argc, char **argv, t_list *list);
void			put_list(t_list list);
long			ft_atoi_push(const char *str);
int				get_lo_value(int *list, int size);
int				get_hi_value(int *list, int size);
void			*ft_memcpy_push(void *dest, const void *src, size_t n);
void			rotate_to_index(t_list *list, int i, int val, char c);
int				get_next_line(const int fd, char **line);
int				check_list_sort(t_list list);
int				one_list_sort(int *list, int size);
int				one_listb_sort(int *list, int size);
int				list_sort_pivot(int *lista, int s1, int pivot, int status);
int				listb_sort_pivot(int *listb, int s2, int pivot);
void			ft_bzero(void *s, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strchrint(const char *s, int c);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *s);
char			**ft_strsplit(char const *s, char c, int *argc);

#endif

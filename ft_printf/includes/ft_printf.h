/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:25:42 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/23 18:38:46 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct	s_flags{
	int		special_print;
	int		zero;
	int		neg;
	int		sign;
	int		space;
	int		minimal_width;
	int		preci;
	int		h_conver;
	int		lu_conver;
	int		ld_conver;
}				t_flags;

typedef	int		(**t_type)(void *a, t_flags options);
int				ft_printf(const char *format, ...);
int				ft_printf_save(const char *str, int n, int print);
int				ft_type_arg(t_type *type);
int				ft_string(void *str, t_flags options);
int				ft_decimal(void *nb, t_flags options);
int				ft_char(void *str, t_flags options);
int				ft_octal(void *nb, t_flags options);
int				count_min_preci(long long nb, int base);
int				ucount_min_preci(unsigned long long nb, int base);
char			*ft_printf_itoa_base(long long nb, char *base,
				t_flags options, char c);
char			*ft_printf_utoa_base(unsigned long long nb, char *base,
				t_flags options, char c);
char			*ft_float_itoa(long double nb, t_flags options);
int				ft_hexa_down(void *nb, t_flags options);
int				ft_hexa_up(void *nb, t_flags options);
int				ft_udecimal(void *nb, t_flags options);
int				ft_memory(void *nb, t_flags options);
int				ft_float(long double nb, t_flags options);
t_flags			ft_printf_pars(const char *str, int *i);
int				ft_separate_nb(const char *str, int *i);
char			*ft_flags_neg(char *str, t_flags options);
char			*ft_f_minwidth(char *str, t_flags options);
char			*ft_zerowpreci(char *str, t_flags options);
char			*strncat_printf(char *dest, const char *src,
				size_t n, size_t len);
void			putstr_printf(char const *s, size_t sie);
char			*ft_f_space(char *str, t_flags options);
char			*ft_strndup(char *str, size_t n);
int				ft_pourcent(t_flags options);
void			flags_pars_nb(const char *str, t_flags *flags, int *i);
char			*ft_fiota_nbspe(long double nb);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(long n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strjoinfree(char *s1, char const *s2);
char			*ft_itoaspefloat(long n);

#endif

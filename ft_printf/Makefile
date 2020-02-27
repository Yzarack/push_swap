# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 10:31:20 by jthierce          #+#    #+#              #
#    Updated: 2019/08/09 13:18:02 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_NAME =	ft_printf.c\
			conversion/type_arg.c\
			conversion/ft_decimal.c\
			conversion/ft_string.c\
			conversion/ft_char.c\
			conversion/ft_octal.c\
			conversion/ft_hexa_down.c\
			conversion/ft_hexa_up.c\
			conversion/ft_udecimal.c\
			conversion/ft_memory.c\
			conversion/ft_float.c\
			conversion/ft_pourcent.c\
			flags/ft_flags_neg.c\
			flags/ft_f_minwidth.c\
			flags/ft_zerowpreci.c\
			flags/ft_f_space.c\
			tools/ft_printf_itoa_base.c\
			tools/ft_printf_utoa_base.c\
			tools/ft_float_itoa.c\
			tools/ft_separate_nb.c\
			tools/count_min_preci.c\
			tools/ucount_min_preci.c\
			tools/strncat_printf.c\
			tools/putstr_printf.c\
			tools/ft_strndup.c\
			tools/flags_pars_nb.c\
			tools/ft_fitoa_nbspe.c\
			tools/ft_itoaspefloat.c\
			mini_libft/ft_atoi.c\
			mini_libft/ft_bzero.c\
			mini_libft/ft_itoa.c\
			mini_libft/ft_memset.c\
			mini_libft/ft_strdup.c\
			mini_libft/ft_strjoin.c\
			mini_libft/ft_strlen.c\
			mini_libft/ft_strncpy.c\
			mini_libft/ft_strjoinfree.c\
			ft_printf_save.c\
			ft_printf_pars.c

LIBPRINTF = includes/ft_printf.h

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src/

OBJ_PATH = obj/

OBJ_FOLDER = obj obj/conversion obj/flags obj/tools obj/mini_libft

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

HEADER = -I includes/

all:
	@make $(NAME)

$(NAME): $(OBJ) $(LIBPRINTF)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_FOLDER) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

.PHONY: fclean all clean re test

clean:
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all
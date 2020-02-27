# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 10:31:20 by jthierce          #+#    #+#              #
#    Updated: 2019/08/09 13:19:34 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project_push_swap

PUSH_SWAP = push_swap

CHECKER = checker

SRC_PUSH_SWAP =	mini_libft/ft_atoi_push.c\
				mini_libft/ft_strlen.c\
				mini_libft/ft_memcpy_push.c\
				mini_libft/ft_bzero.c\
				mini_libft/ft_strsplit.c\
				move/push_a.c\
				move/push_b.c\
				move/rotate_a.c\
				move/rotate_b.c\
				move/rotate_rotate.c\
				move/rrotate_a.c\
				move/rrotate_b.c\
				move/rrotate_rrotate.c\
				move/swap_a.c\
				move/swap_b.c\
				move/swap_swap.c\
				tools/rotate_or_not.c\
				tools/ini_moove_struct.c\
				tools/check_list_sort.c\
				tools/place_of_pivot.c\
				tools/list_sort_pivot.c\
				tools/listb_sort_pivot.c\
				tools/save_pivot.c\
				tools/one_list_sort.c\
				tools/one_listb_sort.c\
				tools/choose_pivot.c\
				tools/create_list.c\
				tools/error_arg.c\
				tools/put_list.c\
				tools/quicksort_part_three.c\
				tools/insertion_sort.c\
				tools/insertion_sortlistb.c\
				tools/rotate_to_index.c\
				tools/get_lo_value.c\
				tools/get_hi_value.c\
				push_swap.c\
				main_push_swap.c\

SRC_CHECKER =	mini_libft/ft_atoi_push.c\
				mini_libft/ft_strlen.c\
				mini_libft/ft_strchr.c\
				mini_libft/ft_memcpy_push.c\
				mini_libft/ft_bzero.c\
				mini_libft/ft_strcmp.c\
				mini_libft/get_next_line.c\
				mini_libft/ft_strchrint.c\
				mini_libft/ft_strncat.c\
				mini_libft/ft_strncpy.c\
				mini_libft/ft_strcpy.c\
				mini_libft/ft_strsplit.c\
				move/push_a.c\
				move/push_b.c\
				move/rotate_a.c\
				move/rotate_b.c\
				move/rotate_rotate.c\
				move/rrotate_a.c\
				move/rrotate_b.c\
				move/rrotate_rrotate.c\
				move/swap_a.c\
				move/swap_b.c\
				move/swap_swap.c\
				tools/create_list.c\
				tools/error_arg.c\
				tools/put_list.c\
				tools/check_list_sort.c\
				checker.c\
				main_checker.c\

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CHERCKER = $(SRC_CHECKER:.c=.o)

SRC_PATH = src/

OBJ_PATH = obj/

OBJ_FOLDER = obj obj/move obj/tools obj/mini_libft

PUSH_SRC = $(addprefix $(SRC_PATH)/, $(SRC_PUSH_SWAP))

PUSH_OBJ = $(addprefix $(OBJ_PATH),$(OBJ_PUSH_SWAP))

CHECKER_SRC = $(addprefix $(SRC_PATH)/, $(SRC_CHECKER))

CHECKER_OBJ = $(addprefix $(OBJ_PATH),$(OBJ_CHERCKER))

HEADER = -I includes/

HEADER_PRINTF = -I ft_printf/includes

PRINTF_PATH = ft_printf

PRINTF = $(PRINTF_PATH)/libftprintf.a



all:
	@make $(NAME)

$(NAME):
	@make -C $(PRINTF_PATH)
	@make $(PUSH_SWAP)
	@make $(CHECKER)


$(PUSH_SWAP): $(PUSH_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTF)

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(HEADER_PRINTF) -o $@ $^ $(PRINTF)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_FOLDER) 2> /dev/null || true
	$(CC) $(CFLAGS) $(HEADER) $(HEADER_PRINTF) -o $@ -c $<

.PHONY: fclean all clean re

clean:
	@make clean -C $(PRINTF_PATH)
	rm -fv $(PUSH_OBJ)
	rm -fv $(CHECKER_OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(PRINTF_PATH)
	rm -rf $(PUSH_SWAP)
	rm -rf $(CHECKER)

re:
	@make fclean
	@make all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 16:33:40 by rufernan          #+#    #+#              #
#    Updated: 2021/09/02 16:33:44 by rufernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =      push_movements.c \
			push_swap.c \
			rotate_movements.c \
			short_lists_sorter.c \
			big_lists_sorter.c \
			stack_operations.c \
			swap_moves.c \
			500_list_sorter.c \
			utils.c \
			find_quartiles.c

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -fno-omit-frame-pointer
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./LIBFT
	@${CC} ${OBJS} ${CFLAGS} ./LIBFT/libft.a -o push_swap

clean:
	@$(MAKE) -C LIBFT fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} push_swap

re: fclean all

.PHONY: clean fclean re all

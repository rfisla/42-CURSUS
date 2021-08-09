# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 02:39:52 by rufernan          #+#    #+#              #
#    Updated: 2021/08/09 02:39:53 by rufernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g

LIBFT = LIBFT

DIR_S = sources

DIR_O = obj

HEADER = includes

SOURCES =  auxiliar_functions.c \
			c_conversor.c \
			ft_printf.c \
			id_conversor.c \
			p_conversor.c \
			s_conversor.c \
			u_conversor.c \
			x_conversor.c 


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp LIBFT/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

test:
	@make all misc/main.c


norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

bonus: re

.PHONY: fclean re norme all clean

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

FLAGS = -Wall -Wextra -Werror

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

#Selecting the sources
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

#Folder where the objects will be save
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

#Main rule
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp LIBFT/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

#checking norme
norme:
	norminette ./LIBFT/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/
# Rule to remove everything that has been created by the makefile.
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

# Rule to re-make everything.
re: fclean all

#bonus rule
bonus: re

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: fclean re norme all clean

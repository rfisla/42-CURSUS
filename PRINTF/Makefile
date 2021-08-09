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

NAME	=	libftprintf.a

SRCS	=	auxiliar_functions.c \
			c_conversor.c \
			ft_printf.c \
			id_conversor.c \
			p_conversor.c \
			s_conversor.c \
			u_conversor.c \
			x_conversor.c 

OBJS =  ${SRCS:.c=.o}

SRCS_DIR = sources
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJECTS))


BONUS	=	auxiliar_functions.c \
			c_conversor.c \
			ft_printf.c \
			id_conversor.c \
			p_conversor.c \
			s_conversor.c \
			u_conversor.c \
			x_conversor.c 

BONUS_OBJS =  ${BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: ${NAME}

${NAME}:	
		${CC} -c ${CFLAGS} ${SRCS} 
		ar crs ${NAME} ${OBJS}
# Rule to remove all the object files and directory.		
clean:
			${RM} ${OBJS} ${BONUS_OBJS}
# Rule to remove everything that has been created by the makefile.
fclean:		clean
				${RM} ${NAME}
# Rule to re-make everything.
re:			fclean all

bonus:		${OBJS} ${BONUS_OBJS}
			ar crs ${NAME} ${OBJS} ${BONUS_OBJS}

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all, clean, fclean, re



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 21:02:57 by rufernan          #+#    #+#              #
#    Updated: 2021/08/31 21:02:58 by rufernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a 

SRCS	= ft_strchr.c  ft_strncmp.c  ft_strjoin.c ft_putchar_fd.c \
		ft_putstr_fd.c  ft_split.c ft_strlen.c

OBJS	=	${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g 

RM		= rm -f

all: ${NAME}

${NAME}:	
		${CC} -c ${CFLAGS} ${SRCS} 
		ar crs ${NAME} ${OBJS}
# Rule to remove all the object files and directory.		
clean:
			${RM} ${OBJS} 
# Rule to remove everything that has been created by the makefile.
fclean:		clean
				${RM} ${NAME}
# Rule to re-make everything.
re:			fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all, clean, fclean, re

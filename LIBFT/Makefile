# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 16:48:52 by rufernan          #+#    #+#              #
#    Updated: 2021/05/26 16:48:55 by rufernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a 

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_calloc.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
		ft_substr.c ft_strjoin.c

OBJS	=	${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g 

RM		= rm -f

all: ${NAME}

${NAME}:	
		${CC} -c ${CFLAGS} ${SRCS} 
		ar crs ${NAME} ${OBJS}
		
clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY: all, clean, fclean, re

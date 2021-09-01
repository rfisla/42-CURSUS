NAME = pipex.a

SRCS =      sources/pipex.c \
			sources/path_parser.c \
			sources/utils.c 

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=leak
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./LIBFT
	@${CC} ${OBJS} ${CFLAGS} ./LIBFT/libft.a -o pipex

clean:
	@$(MAKE) -C LIBFT fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} pipex

re: fclean all

.PHONY: clean fclean re all
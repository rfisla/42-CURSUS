NAME = minishell

SRCS =      minishell.c \
			frees.c \
			builtins.c

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -fsanitize=address -fno-omit-frame-pointer
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./LIBFT
	@${CC} ${OBJS} ${CFLAGS} ./LIBFT/libft.a -o minishell

clean:
	@$(MAKE) -C LIBFT fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} minishell

re: fclean all

.PHONY: clean fclean re all
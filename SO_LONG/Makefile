C = gcc

NAME = so_long.a

CFLAGS = -Werror -Wall -Wextra

MINILIBX = ./minilibx/libmlx.a  -lmlx -framework OpenGL -framework AppKit 

OBJS := $(*.o)

SRC = so_long.c


all: $(NAME)

${NAME}: fclean
	${CC} ${CFLAGS} ${MINILIBX} ${SRC}  -o ${NAME}

clean:
	rm -rf *.o


fclean: clean
	rm -f  ${OBJS} $(NAME)

re: fclean ${NAME}
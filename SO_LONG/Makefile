
NAME = so_long

SRCS			=	so_long.c \
				sources/map_checks.c \
				sources/map_checks2.c \
				sources/map_parsing.c \
				sources/frees.c \
				sources/init_game.c \
				sources/draw_map.c \
				sources/events.c \
				sources/player_movement.c


OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
MLXFLAGS = -lXext -lX11 -lm -lbsd
#FOR MAC -> MINILIBX = -I /usr/X11/include -g  -l mlx -framework OpenGL -framework AppKit
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./LIBFT
	@$(MAKE) -C ./minilibx
	@${CC} ${OBJS} ${CFLAGS} ./LIBFT/libft.a ./minilibx/libmlx.a ${MLXFLAGS} -o so_long

clean:
	@$(MAKE) -C LIBFT fclean
	@$(MAKE) -C minilibx clean
	@${RM} ${OBJS}

fclean: clean
	@${RM} so_long

re: fclean all

.PHONY: clean fclean re all
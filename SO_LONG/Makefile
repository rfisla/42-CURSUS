
NAME = 		so_long
NAME_BONUS = so_long_bonus

SRCS			=	so_long.c \
				sources/map_checks.c \
				sources/map_checks2.c \
				sources/map_parsing.c \
				sources/frees.c \
				sources/init_game.c \
				sources/draw_map.c \
				sources/events.c \
				sources/player_movement.c

SRCS_BONUS		=	bonus/so_long_bonus.c \
				bonus/map_checks_bonus.c \
				bonus/map_checks2_bonus.c \
				bonus/map_parsing_bonus.c \
				bonus/frees_bonus.c \
				bonus/init_game_bonus.c \
				bonus/draw_map_bonus.c \
				bonus/events_bonus.c \
				bonus/player_movement_bonus.c


OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
MLXFLAGS = -lXext -lX11 -lm -lbsd
#FOR MAC -> MINILIBX = -I /usr/X11/include -g  -l mlx -framework OpenGL -framework AppKit
RM = rm -rf

all: 	${NAME}
bonus:	$(NAME_BONUS)

${NAME}: ${OBJS}
	@$(MAKE) -C ./LIBFT
	@$(MAKE) -C ./minilibx
	@${CC} ${OBJS} ${CFLAGS} ./LIBFT/libft.a ./minilibx/libmlx.a ${MLXFLAGS} -o so_long

${NAME_BONUS}: ${OBJS_BONUS}
	@$(MAKE) -C ./LIBFT
	@$(MAKE) -C ./minilibx
	@${CC} ${OBJS_BONUS} ${CFLAGS} ./LIBFT/libft.a ./minilibx/libmlx.a ${MLXFLAGS} -o so_long_bonus

clean:
	@$(MAKE) -C LIBFT fclean
	@$(MAKE) -C minilibx clean
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} so_long so_long_bonus

re: fclean all

.PHONY: clean fclean re all
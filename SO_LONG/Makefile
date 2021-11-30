CC = gcc

NAME = so_long

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

MINILIBXPATH = ./minilibx/
MINILIBX = $(MINILIBX_PATH)/libmlx.a 
MINILIBX_FLAGS = -L. -lXext -L. -lX11
#FOR MAC -> MINILIBX = -I /usr/X11/include -g  -l mlx -framework OpenGL -framework AppKit

OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

SRC			=	so_long.c \
				sources/map_checks.c \
				sources/map_checks2.c \
				sources/map_parsing.c \
				sources/frees.c \
				sources/init_game.c \
				sources/draw_map.c \
				sources/events.c \
				sources/player_movement.c

LIBFTPATH = ./LIBFT/
LIBFTNAME = libft.a

all:		$(NAME)

${NAME}: 
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} ${LIBFTNAME} ${MINILIBX} ${MINILIBX_FLAGS}  -o ${NAME}

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			
			$(MAKE) -C $(LIBFTPATH) clean
			$(MAKE) -C $(MINILIBXPATH) clean
			@rm -rf $(OBJ) obj

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: 	fclean ${NAME}

.PHONY:		all clean fclean re
#ifndef SO_LONG_H
# define SO_LONG_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>
# include "LIBFT/libft.h"


typedef struct s_coords{
    int	x;
	int	y;
} t_coords;

typedef struct s_game
{
	
	char	**map;
	//int **map;
	int	width;
	int	heigh;
	//t_coords	player;
	//t_coords	exit;
	//t_coords	*col;
	int	move_up;
	int	move_down;
	int	move_right;
	int	move_left;
	int	count_moves;
	int	player_char;
	int	exit_char;
	int	col_char;
	//t_coords	player;
	//t_coords	exit;
	//t_coords	*col;
}  t_game;

void			map_parser(char *map, t_game *game);
void			valid_map(char *file, t_game *game);
void			free_game(t_game *game, char *file);
t_game			*init(t_game *game);


#endif
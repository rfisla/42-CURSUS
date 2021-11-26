/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:38:22 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:38:23 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "LIBFT/libft.h"


typedef struct s_coords{
    int	x;
	int	y;
} t_coords;

typedef struct s_images
{
	//void 			*img;
	char 			*addr;
	int				bits_per_pixel;
	int				size_line;
	int 			endian;

}				t_images;

typedef struct s_game
{
	
	char	**map;
	//int **map;
	int	width;
	int	heigh;
	int	playerpos_x;
	int playerpos_y;
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
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	void			*player;
	void			*exit;
	void			*coll;
	void			*wall;
	void			*ground;
}  t_game;




void			map_parser(char *map, t_game *game);
void			valid_map(char *file, t_game *game);
void			free_invalid_map(t_game *game, char *file);
t_game			*init(t_game *game);
void		game_init(char *file, t_game *game);
int		draw_map(t_game *game);
int	keypress(int keycode, t_game *game);
void	events(int keycode, t_game *game);
int		exit_game(int keycode, t_game *game);
int    exit_and_free(t_game *game);
void	make_movement (t_game *game, int keycode);








#endif

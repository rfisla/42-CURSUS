/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:37:08 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:37:10 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

static void	loading_image(t_game *display, void **element,  char *path)
{
	int				width;
	int				height;

	*element= mlx_xpm_file_to_image(display->mlx, path, &width, &height);
	//if (*img == 0)
		//root_destroy(0, "texture_init(): can't load texture", 0);
}

static void	display_init(t_game *display)
{
	loading_image(display, &display->player, "./images2/worker.xpm");
	loading_image(display, &display->exit, "./images2/house.xpm");
	loading_image(display, &display->coll, "./images2/collectible.xpm");
	loading_image(display, &display->wall, "./images/wall.xpm");
	loading_image(display, &display->ground, "./images2/ground.xpm");
}

static void	renderer_init(t_game *game)
{
	game->mlx = mlx_init();
	//if (display->mlx == 0)
		//root_destroy(root, "mlx_init(): can't load mlx", 0);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 80 ,
			game->heigh * 80, "SO_LONG");
	//if (display->mlx_win == 0)
		//root_destroy(display, "mlx_new_window(): can't create a window", 0);
	game->mlx_img = mlx_new_image(game->mlx, game->width * 80,
			game->heigh * 80);
	//if (display->mlx_img == 0)
		//root_destroy(root, "mlx_new_image(): can't create an image", 0);	
}



void    game_init(char *file, t_game *game)
{
	init(game);
	map_parser(file, game);
	renderer_init(game);
	display_init(game);
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, keypress, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->mlx_win, 9, 1L << 21, draw_map, game);
	mlx_loop(game->mlx);
}

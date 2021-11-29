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

static void	loading_image(t_game *game, void **element, char *path)
{
	int	width;
	int	height;

	*element = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*element == 0)
	{
		free_map(game->map);
		//mlx_destroy_window(game->mlx, game->mlx_win);
		//free(game->mlx);
		ft_putendl_fd("Error:\nProblem with the images", 2);
		exit(0);
	}
}

static void	upload_images(t_game *display)
{
	loading_image(display, &display->player, "./images32/worker.xpm");
	loading_image(display, &display->exit, "./images32/house.xpm");
	loading_image(display, &display->coll, "./images32/collectible.xpm");
	loading_image(display, &display->wall, "./images32/wall.xpm");
	loading_image(display, &display->ground, "./images/ground.xpm");
}

static void	create_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 32,
			game->heigh * 32, "SO_LONG");
	game->mlx_img = mlx_new_image(game->mlx, game->width * 32,
			game->heigh * 32);
	/*
	if (game->mlx == 0 || game->mlx_win || game->mlx_img == 0)
	{
		free_map(game->map);
		ft_putendl_fd("Error:\nProblem with the images", 2);
		exit(0);
	}
	*/
}

void	game_init(t_game *game)
{
	create_window(game);
	upload_images(game);
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, keypress, game);
	//mlx_hook(game->mlx_win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->mlx_win, 9, 1L << 21, draw_map, game);
	mlx_loop(game->mlx);
}

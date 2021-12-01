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

#include "so_long_bonus.h"

void	loading_image(t_game *game, void **element, char *path)
{
	int	width;
	int	height;

	*element = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*element == 0)
	{
		free_map(game->map);
		ft_putendl_fd("Error:\nProblem with the images", 2);
		exit(0);
	}
}

static void	upload_images(t_game *display)
{
	loading_image(display, &display->player, "./images/mario_start.xpm");
	loading_image(display, &display->exit, "./images/exit.xpm");
	loading_image(display, &display->coll, "./images/star.xpm");
	loading_image(display, &display->wall, "./images/wall2.xpm");
	loading_image(display, &display->ground, "./images/ground.xpm");
	if (display->enemy_char > 0)
		loading_image(display, &display->enemy, "./images/enemy.xpm");
}

static void	create_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 40,
			game->heigh * 40, "SO_LONG");
	game->mlx_img = mlx_new_image(game->mlx, game->width * 40,
			game->heigh * 40);
	if (game->mlx == 0 || game->mlx_win == 0 || game->mlx_img == 0)
	{
		free_map(game->map);
		ft_putendl_fd("Error:\nProblem with the images", 2);
		exit(0);
	}
}

void	game_init(t_game *game)
{
	create_window(game);
	upload_images(game);
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, keypress, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, exit_and_free, game);
	mlx_hook(game->mlx_win, 9, 1L << 21, draw_map, game);
	mlx_loop(game->mlx);
}

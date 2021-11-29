/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:36:46 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:36:47 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_square(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image, x * 32, y * 32);
}

static void	drawing_player(t_game *game, void *image, int x, int y)
{
	game->playerpos_x = x;
	game->playerpos_y = y;
	draw_square(game, image, x, y);
}

int	draw_map(t_game *game)
{
	int				i;
	int				j;

	j = 0;
	while (j < game->heigh)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == '1')
				draw_square(game, game->wall, i, j);
			else if (game->map[j][i] == 'E')
				draw_square(game, game->exit, i, j);
			else if (game->map[j][i] == 'C')
				draw_square(game, game->coll, i, j);
			else if (game->map[j][i] == 'P')
				drawing_player(game, game->player, i, j);
			else
				draw_square(game, game->ground, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

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

#include "so_long_bonus.h"

static void	draw_square(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image, \
							x * 40, y * 40 + 25);
}

static void	drawing_player(t_game *game, void *image, int x, int y)
{
	game->playerpos_x = x;
	game->playerpos_y = y;
	draw_square(game, image, x, y);
}

static void	detect_draw(t_game *game, int j, int i)
{
	if (game->map[j][i] == '1')
		draw_square(game, game->wall, i, j);
	else if (game->map[j][i] == 'E')
		draw_square(game, game->exit, i, j);
	else if (game->map[j][i] == 'C')
		draw_square(game, game->coll, i, j);
	else if (game->map[j][i] == 'P')
		drawing_player(game, game->player, i, j);
	else if (game->map[j][i] == 'G')
		draw_square(game, game->enemy, i, j);
	else
		draw_square(game, game->ground, i, j);
}

static void	display_movements(t_game *game)
{
	char	*number;

	number = ft_itoa(game->count_moves);
	mlx_string_put(game->mlx, game->mlx_win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->mlx_win, 70, 20, 0xFFFFFF, number);
	free(number);
}

int	draw_map(t_game *game)
{
	int				i;
	int				j;

	j = 0;
	while (j < game->heigh)
	{
		i = 0;
		while (i <= game->width)
		{
			detect_draw(game, j, i);
			i++;
		}
		j++;
	}
	display_movements(game);
	return (0);
}

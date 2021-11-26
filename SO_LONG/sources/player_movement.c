/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:40:18 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 16:40:43 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	up_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	if (game->map[pos_y][pos_x] == '1' || \
	(game->map[pos_y][pos_x] == 'E' && game->col_char > 0))
		game->playerpos_y++;
	else if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y + 1][pos_x] = '0';
		draw_map(game);
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[pos_y + 1][pos_x] = '0';
		draw_map(game);
		game->count_moves++;
		game->exit_char--;
	}
}

static void	right_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	if (game->map[pos_y][pos_x] == '1' || \
	(game->map[pos_y][pos_x] == 'E' && game->col_char > 0))
		game->playerpos_x--;
	else if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y][pos_x - 1] = '0';
		draw_map(game);
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[pos_y][pos_x - 1] = '0';
		draw_map(game);
		game->count_moves++;
		game->exit_char--;
	}
}

static void	left_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	if (game->map[pos_y][pos_x] == '1' || \
	(game->map[pos_y][pos_x] == 'E' && game->col_char > 0))
		game->playerpos_x++;
	else if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y][pos_x + 1] = '0';
		draw_map(game);
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[pos_y][pos_x + 1] = '0';
		draw_map(game);
		game->count_moves++;
		game->exit_char--;
	}
}

static void	down_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	if (game->map[pos_y][pos_x] == '1' || \
	(game->map[pos_y][pos_x] == 'E' && game->col_char > 0))
		game->playerpos_y--;
	else if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y - 1][pos_x] = '0';
		draw_map(game);
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[pos_y - 1][pos_x] = '0';
		draw_map(game);
		game->count_moves++;
		game->exit_char--;
	}
}

void	make_movement (t_game *game, int keycode)
{
	if (keycode == 13)
	{
		game->move_up++;
		game->playerpos_y -= 1;
		up_movement(game);
	}
	else if (keycode == 0)
	{
		game->move_left++;
		game->playerpos_x -= 1;
		left_movement(game);
	}
	else if (keycode == 1)
	{
		game->move_down++;
		game->playerpos_y += 1;
		down_movement(game);
	}
	else if (keycode == 2)
	{
		game->move_right++;
		game->playerpos_x += 1;
		right_movement(game);
	}
	//if (!game->exit_char)
}

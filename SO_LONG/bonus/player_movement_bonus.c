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

#include "so_long_bonus.h"

static void	up_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	change_player_img(game, 1);
	if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y + 1][pos_x] = '0';
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		game->map[pos_y + 1][pos_x] = '0';
		game->count_moves++;
		game->exit_char--;
	}
	else
		game->playerpos_y++;
	draw_map(game);
	check_enemy_found(game, pos_y, pos_x);
}

static void	right_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	change_player_img(game, 2);
	if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y][pos_x - 1] = '0';
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		game->map[pos_y][pos_x - 1] = '0';
		game->count_moves++;
		game->exit_char--;
	}
	else
		game->playerpos_x--;
	draw_map(game);
	check_enemy_found(game, pos_y, pos_x);
}

static void	left_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	change_player_img(game, 3);
	if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y][pos_x + 1] = '0';
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		game->map[pos_y][pos_x + 1] = '0';
		game->count_moves++;
		game->exit_char--;
	}
	else
		game->playerpos_x++;
	draw_map(game);
	check_enemy_found(game, pos_y, pos_x);
}

static void	down_movement(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->playerpos_x;
	pos_y = game->playerpos_y;
	change_player_img(game, 4);
	if (game->map[pos_y][pos_x] == '0' || game->map[pos_y][pos_x] == 'C')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->col_char--;
		game->map[pos_y][pos_x] = 'P';
		game->map[pos_y - 1][pos_x] = '0';
		game->count_moves++;
	}
	else if (game->map[pos_y][pos_x] == 'E' && game->col_char == 0)
	{
		game->map[pos_y - 1][pos_x] = '0';
		game->count_moves++;
		game->exit_char--;
	}
	else
		game->playerpos_y--;
	draw_map(game);
	check_enemy_found(game, pos_y, pos_x);
}

void	make_movement (t_game *game, int keycode)
{
	if (keycode == 119)
	{
		game->move_up++;
		game->playerpos_y -= 1;
		up_movement(game);
	}
	else if (keycode == 97)
	{
		game->move_left++;
		game->playerpos_x -= 1;
		left_movement(game);
	}
	else if (keycode == 115)
	{
		game->move_down++;
		game->playerpos_y += 1;
		down_movement(game);
	}
	else if (keycode == 100)
	{
		game->move_right++;
		game->playerpos_x += 1;
		right_movement(game);
	}
}

/*
KEYBOARD KEYCODES

Linux:
W->119, S->115, A->97, D->100

MAC:
W->13, S->1, A->0, D->2
*/

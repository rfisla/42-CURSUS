/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:36:22 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:36:24 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
 
/*
# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
*/
/*
void	events(int keycode, t_game *game)
{
	if (keycode == 119)
	{
		game->move_up++;
		game->playerpos_y -= 1;
	}
	else if (keycode == 97)
	{
		game->move_left++;
		game->playerpos_x -= 1;
	}
	else if (keycode == 115)
	{
		game->move_down++;
		game->playerpos_y += 1;
	}
	else if (keycode == 100)
	{
		game->move_right++;
		game->playerpos_x += 1;
	}

}
*/
int	keypress(int keycode, t_game *game)
{
	char prev_count;

	prev_count = game->count_moves;
	make_movement(game, keycode);
	if (prev_count != game->count_moves)
		ft_putendl_fd(ft_itoa(game->count_moves), 0);
	return (0);
}
int	exit_game(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_and_free(game);
	return (0);
}
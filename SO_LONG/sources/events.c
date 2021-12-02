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

//Scape keycode: Linux = 65307, MAC = 53

void	change_player_img(t_game *game, int i)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->player);
	if (i == 1)
		loading_image(game, &game->player, "./images/mario_up.xpm");
	else if (i == 2)
		loading_image(game, &game->player, "./images/mario_right.xpm");
	else if (i == 3)
		loading_image(game, &game->player, "./images/mario_left.xpm");
	else if (i == 4)
		loading_image(game, &game->player, "./images/mario_down.xpm");
}

int	exit_game(int keycode, t_game *game)
{
	if (keycode == 53 || !game->exit_char)
		exit_and_free(game);
	return (0);
}

int	keypress(int keycode, t_game *game)
{
	char	prev_count;

	prev_count = game->count_moves;
	make_movement(game, keycode);
	if (prev_count != game->count_moves)
		printf("%d\n", game->count_moves);
	exit_game(keycode, game);
	return (0);
}

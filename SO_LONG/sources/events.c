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
		ft_putendl_fd(ft_itoa(game->count_moves), 0);
	exit_game(keycode, game);
	return (0);
}

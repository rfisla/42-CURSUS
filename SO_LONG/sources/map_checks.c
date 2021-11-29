/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:37:20 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:37:22 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_width(t_game *game, char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\n')
	{
		game->width++;
		if (file[i + 1] == '\0' && file[i] != '\n')
			invalid_map(game, file);
		i++;
	}
	//game->width++;
	if (game->width == 0)
		invalid_map(game, file);
}

static void	map_heigh(t_game *game, char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n' && file[i + 1] != '\0' && file[i + 1] != '\n')
			game->heigh++;
		i++;
	}
	game->heigh++;
	if (game->heigh == 0)
		invalid_map(game, file);
}

static void	valid_char_checker(t_game *game, char *file, int i)
{
	if (file[i] == 'P')
		game->player_char++;
	else if (file[i] == 'E')
		game->exit_char++;
	else if (file[i] == 'C')
		game->col_char++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
		invalid_map(game, file);
}

void	valid_map(char *file, t_game *game)
{
	int	i;

	i = 0;
	map_width(game, file);
	map_heigh(game, file);
	//if (!border_checker(file, game) || game->heigh > game->width || 
		//!rows_same_length(file, game))
		//invalid_map(game, file);
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			i++;
		else
		{
			valid_char_checker(game, file, i);
			i++;
		}	
	}
	if (game->player_char != 1 || game->exit_char != 1 || game->col_char < 1)
		invalid_map(game, file);
}

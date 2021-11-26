/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:36:56 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:36:57 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  void    free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void    free_invalid_map(t_game *game, char *file)
{
    free(file);
    if (game->map)
	{
        free_map(game->map);
		game->map = 0;
	}
    free(game);
	ft_putendl_fd("Invalid map", 2);
	exit(0);

}


int	exit_and_free(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coll);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_window(game->mlx, game->mlx_win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

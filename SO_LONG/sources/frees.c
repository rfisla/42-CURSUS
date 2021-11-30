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

void	invalid_file(char **file, int fd)
{
	free(*file);
	close(fd);
	ft_putendl_fd("Error:\nInvalid file", 2);
	exit(0);
}

void	invalid_map(t_game *game, char *file)
{
	free(file);
	if (game)
		free(game);
	ft_putendl_fd("Error:\nInvalid map", 2);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = 0;
}

int	exit_and_free(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coll);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_map(game->map);
	if (game->exit_char == 0)
		printf("GOOD JOB!\n");
	else if (game->exit_char == 1)
		printf("TRY AGAIN :(\n");
	exit(0);
	return (0);
}

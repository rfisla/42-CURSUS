/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:37:30 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/26 14:37:32 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void map_read(char *map, char **file, t_game *game)
{
	int		fd;
	int		ret;
	char	buf[1024];
	char	*tmp;

	fd = open(map, O_RDONLY);
	*file = ft_calloc(1,1);
	ret = 1;
	if (fd < 0 || *file == 0)
	{
		close(fd);
		free_invalid_map(game, *file);
	}
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			close(fd);
			free_invalid_map(game, *file);
		}
		else
		{
			buf[ret] = 0;
			tmp = ft_strjoin(*file, buf);
			free(*file);//Lo hce directamente el strjoin
			*file = tmp;
			if (*file == 0)
			{
				close(fd);
				free_invalid_map(game, *file);
			}
		}
	}
	close(fd);
}

void    map_parser(char *argv, t_game *game)
{
    int		x;
    int		y;
    int		i;
    //int		n_col;
	char	*file;
    y = 0;
    i = 0;
    //n_col = 0;
	map_read(argv, &file, game);
    valid_map(file, game);
	game->map = (char **)malloc(sizeof(char *) * game->heigh);
	if (!game->map)
        free_invalid_map(game, file);
    while (y < game->heigh)
    {
		game->map[y] = (char *)malloc(sizeof(char) * game->width);
		if (!game->map[y])
        	free_invalid_map(game, file);
		x = 0;
        while (x < game->width)
        {
            game->map[y][x] = file[i++];
            x++;
        }
		i++;
        y++;
    }
	free(file);
}

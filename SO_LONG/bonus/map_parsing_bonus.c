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

#include "so_long_bonus.h"

static void	map_read(char **file, int fd)
{
	int		ret;
	char	buf[1024];
	char	*tmp;

	*file = ft_calloc(1, 1);
	ret = 1;
	if (fd < 0 || *file == 0)
		invalid_file(file, fd);
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
			invalid_file(file, fd);
		else
		{
			buf[ret] = 0;
			tmp = ft_strjoin(*file, buf);
			free(*file);
			*file = tmp;
			if (*file == 0)
				invalid_file(file, fd);
		}
	}
}

void	map_parser(char *argv, t_game *game)
{
	int		fd;
	char	*file;

	fd = open(argv, O_RDONLY);
	map_read(&file, fd);
	close(fd);
	valid_map(file, game);
	game->map = ft_split(file, '\n');
	free(file);
}

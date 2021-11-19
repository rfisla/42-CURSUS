/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:39 by rufernan          #+#    #+#             */
/*   Updated: 2021/11/04 14:50:41 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


static int	check_file(char *argv)
{
	int				len;

	len = ft_strlen(argv);
	if (argv == 0 || len < 5)
		return (0);
	if (ft_strncmp(argv + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}
t_game *init(t_game *game)
{
	game->width = 0;
	game->heigh = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_right = 0;
	game->move_left = 0;
	game->count_moves = 0;
	game->player_char = 0;
	game->exit_char = 0;
	game->col_char = 0;
	return (game);
}

int main (int argc, char **argv)
{
	t_game *game;
	char *file;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid number of arguments", 2);
		exit(0);
	}
	if (!check_file(argv[1]))
	{
		ft_putendl_fd("File is not .ber", 2);
		exit(0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	init(game);
	map_parser(argv[1], game);
	int y = 0;
	int x;
	while (y < game->heigh)
    {
		x = 0;
        while (x < game->width)
        {
            printf("%c",game->map[y][x]);
            x++;
        }
        y++;
    }
	return(0);
}
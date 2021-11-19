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

void    free_game(t_game *game, char *file)
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

#include "../so_long.h"

static void	map_width(t_game *game, char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\n')
	{
		game->width++;
		i++;
	}
	if (game->width == 0)
		free_game(game, file);
}

static void	map_heigh(t_game *game, char *file)
{
	int		i;

	i = 0;
	while(file[i] != '\0')
	{
		if (file[i] == '\n')
			game->heigh++;
		i++;
	}
	game->heigh++;
	if (game->heigh == 0)
		free_game(game, file);
}

static int	border_checker(char *file, t_game *game)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (i < game->width && file[i] != '1')
			return (0);
		if (file[i + 1] == '\n' && file[i] != '1')
			return (0);
		if (file[i] == '\n' && file[i + 1] != '1')
			return (0);
		if (i > (game->width * (game->heigh - 1) + 3) && file[i] != '1')
			return(0);
		i++;
	}
	return (1);
}

static int	rows_same_length(char *file, t_game *game)
{
	int	i;
	int	length;

	i = game->width + 1;
	length = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n' && length != game->width)
			return (0);
		if (file[i] == '\n')
			length = 0;
		i++;
		length++;
	}
	return(1);
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
		free_game(game, file);
}

void	valid_map(char *file, t_game *game)
{
	int	i;

	i = 0;
	map_width(game, file);
	map_heigh(game, file);
	if (!border_checker(file, game) || game->heigh > game->width || \
		rows_same_length(file, game))
		free_game(game, file);
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
		free_game(game, file);
}

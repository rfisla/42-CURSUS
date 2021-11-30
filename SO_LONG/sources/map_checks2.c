#include "../so_long.h"

static int	check_last_line(char *file, t_game *game, int i)
{
	int	last_line;

	last_line = 0;
	i--;
	while (file[i] != '\n')
	{
		if (file[i] != '1' && file[i] != '\n')
			return (0);
		i--;
		last_line++;
	}
	if (last_line != game->width)
		return (0);
	return (1);
}

int	border_checker(char *file, t_game *game)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n' && (file[i + 1] == '\n' || !file[i + 1]))
			break ;
		else if (i < game->width && file[i] != '1')
			return (0);
		else if (file[i + 1] == '\n' && file[i] != '1')
			return (0);
		else if (file[i] == '\n' && file[i + 1] != '1')
			return (0);
		i++;
	}
	if (!check_last_line(file, game, i))
		return (0);
	return (1);
}

int	rows_same_length(char *file, t_game *game)
{
	int	i;
	int	length;
	int	j;

	i = game->width + 1;
	length = 0;
	j = 0;
	while (file[i] != '\0' && j <= game->heigh)
	{
		if (file[i] == '\n' && length != game->width)
			return (0);
		if (file[i] == '\n')
		{
			length = -1;
			j++;
		}
		if (file[i] == '\n' && file[i + 1] != '1')
			break ;
		i++;
		length++;
	}
	return (1);
}

#include "../so_long.h"
/*
static unsigned int	mlx_get_pixel(t_images *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (x * img->bits_per_pixel / 8 + y * img->size_line)));
}

static void	mlx_put_pixel(t_images *image, int x, int y, int color)
{
	char			*target;

	target = image->addr + (x * image->bits_per_pixel / 8 + y * image->size_line);
	*(unsigned int *)target = color;
}
*/
static void	draw_square(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image, x * 80, y * 80);
}

void	draw_map(t_game *game)
{
	int				i;
	int				j;

	j = 0;
	while (j < game->heigh)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == '1')
				draw_square(game, game->wall, i, j);
			else if (game->map[j][i] == 'E')
				draw_square(game, game->exit, i, j);
			else if (game->map[j][i] == 'C')
				draw_square(game, game->coll, i, j);
			else if (game->map[j][i] == 'P')
				draw_square(game, game->player, i, j);
			else
				draw_square(game, game->ground, i, j);
			i++;
		}
		j++;
	}
	//mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
	mlx_loop(game->mlx);
}

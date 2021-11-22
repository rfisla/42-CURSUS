#include "../so_long.h"

static unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char			*target;

	target = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)target = color;
}

static void	draw_square(t_images *display, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			mlx_put_pixel(display->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_game *game, t_images *display)
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
				draw_square(display, display->wall, i * 40, j * 40);
			else if (game->map[j][i] == 'E')
				draw_square(display, display->exit, i * 40, j * 40);
			else if (game->map[j][i] == 'C')
				draw_square(display, display->coll, i * 40, j * 40);
			else if (game->map[j][i] == 'P')
				draw_square(display, display->player, i * 40, j * 40);
			else
				draw_square(display, display->ground, i * 40, j * 40);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(display->mlx, display->mlx_win, display->mlx_img, 0, 0);
	mlx_loop(display->mlx);
}

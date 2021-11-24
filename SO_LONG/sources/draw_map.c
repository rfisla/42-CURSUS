#include "../so_long.h"

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

static void	draw_square(t_game *game, t_images *image, int x, int y)
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
			image->addr = mlx_get_data_addr(game->mlx_img, &image->bits_per_pixel, &image->size_line, &image->endian);
			color = mlx_get_pixel(image, i, j);
			mlx_put_pixel(image, x + i, y + j, color);
			i++;
		}
		j++;
	}
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
			{	
				game->wall = (t_images *)malloc(sizeof(t_images));
				draw_square(game, game->wall, i * 40, j * 40);
			}
			else if (game->map[j][i] == 'E')
			{	
				game->wall = (t_images *)malloc(sizeof(t_images));
				draw_square(game, game->exit, i * 40, j * 40);
			}
			else if (game->map[j][i] == 'C')
			{	
				game->wall = (t_images *)malloc(sizeof(t_images));
				draw_square(game, game->coll, i * 40, j * 40);
			}
			else if (game->map[j][i] == 'P')
			{	
				game->wall = (t_images *)malloc(sizeof(t_images));
				draw_square(game, game->player, i * 40, j * 40);
			}
			else
			{	
				game->wall = (t_images *)malloc(sizeof(t_images));
				draw_square(game, game->ground, i * 40, j * 40);
				//free(game->wall);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
	mlx_loop(game->mlx);
}

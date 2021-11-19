
#include "../so_long.h"

static void	loading_image(t_images *display, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(display->mlx, path, &width, &height);
	//if (*img == 0)
		//root_destroy(0, "texture_init(): can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	display_init(t_images *display)
{
	loading_image(display, &display->player, "./images/worker.xpm");
	loading_image(display, &display->exit, "./images/house.xpm");
	loading_image(display, &display->coll, "./images/collectible.xpm");
	loading_image(display, &display->wall, "./images/wall.xpm");
	loading_image(display, &display->ground, "./images/ground.xpm");
}

static void	renderer_init(t_images *display, t_game *game)
{
	display->mlx = mlx_init();
	//if (display->mlx == 0)
		//root_destroy(root, "mlx_init(): can't load mlx", 0);
	display->mlx_win = mlx_new_window(display->mlx, game->width * 40,
			game->heigh * 40, "SO_LONG");
	//if (display->mlx_win == 0)
		//root_destroy(display, "mlx_new_window(): can't create a window", 0);
	display->mlx_img = mlx_new_image(display->mlx, game->width * 40,
			game->heigh * 40);
	//if (display->mlx_img == 0)
		//root_destroy(root, "mlx_new_image(): can't create an image", 0);
}

t_images    *game_init(char *file, t_game *game)
{
	t_images    *display;

	map_parser(file, game);
    display = (t_images *)malloc(sizeof(t_images));
	//if (display == 0)
	display->mlx = 0;
	display->mlx_win = 0;
	display->mlx_img = 0;
	display->player = 0;
	display->exit = 0;
	display->coll = 0;
	display->wall = 0;
	display->ground = 0;
	renderer_init(display, game);
	display_init(display);
	return (display);
}

#include "../so_long.h"

static void	loading_image(t_game *display, t_images **element,  char *path)
{
	int				width;
	int				height;

	*element= mlx_xpm_file_to_image(display->mlx, path, &width, &height);
	//if (*img == 0)
		//root_destroy(0, "texture_init(): can't load texture", 0);
	//(*display_char)->width = width;
	//(*display_char)->height = height;
}

static void	display_init(t_game *display)
{
	loading_image(display, &display->player, "./images/worker.xpm");
	loading_image(display, &display->exit, "./images/house.xpm");
	loading_image(display, &display->coll, "./images/collectible.xpm");
	loading_image(display, &display->wall, "./images/wall.xpm");
	loading_image(display, &display->ground, "./images/ground.xpm");
}

static void	renderer_init(t_game *game)
{
	game->mlx = mlx_init();
	//if (display->mlx == 0)
		//root_destroy(root, "mlx_init(): can't load mlx", 0);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 40,
			game->heigh * 40, "SO_LONG");
	//if (display->mlx_win == 0)
		//root_destroy(display, "mlx_new_window(): can't create a window", 0);
	game->mlx_img = mlx_new_image(game->mlx, game->width * 40,
			game->heigh * 40);
	//if (display->mlx_img == 0)
		//root_destroy(root, "mlx_new_image(): can't create an image", 0);
	//mlx_loop(display->mlx);
	//mlx_put_image_to_window(display->mlx, display->mlx_win, display->player, 10, 10);
	
	
}


void    game_init(char *file, t_game *game)
{
	init(game);
	map_parser(file, game);
	renderer_init(game);
	display_init(game);
	draw_map(game);
	//return (display);
}
#include "so_long.h"

void	sprites_init(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm",
			&game->wall.w, &game->wall.h);
	game->start.img = mlx_xpm_file_to_image(game->mlx, "sprite/start.xpm",
			&game->start.w, &game->start.h);
	game->cat_sp.img = mlx_xpm_file_to_image(game->mlx, "sprite/cat.xpm",
			&game->cat_sp.w, &game->cat_sp.h);
	game->steak.img = mlx_xpm_file_to_image(game->mlx, "sprite/steak.xpm",
			&game->steak.w, &game->steak.h);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "sprite/exit.xpm",
			&game->exit.w, &game->exit.h);
	game->bg.img = mlx_xpm_file_to_image(game->mlx, "sprite/background.xpm",
			&game->bg.w, &game->bg.h);
	// vars->yw_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/yw_sp.xpm",
	// 		&vars->yw_sp.px_w, &vars->yw_sp.px_h);
}

void	sprite_print(t_game *game, t_point pos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img, pos.x,
				pos.y);
	else if (c == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->start.img, pos.x,
				pos.y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->steak.img, pos.x,
				pos.y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->steak.img, pos.x,
				pos.y);
	// else if (c == 'F')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->steak.img, pos.x,
	// 			pos.y);
}
#include "so_long.h"

void sprite_init(t_game *game)
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

void bg_print(t_game *game)
{
	t_point a;
	t_point m;

	a.x = 0;
	a.y = 0;
	m.x = game->map.width * 50;
	// ft_printf("%d\n", game->map.width);
	m.y = game->map.height * 50;
	while (a.x < m.x)
	{
		while (a.y < m.y)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->bg.img, a.x,
									a.y);
			a.y += 50;
		}
		a.y = 0;
		a.x += 50;
	}
}

void map_print(t_game *game)
{
	t_point a;

	a.x = 0;
	a.y = 0;
	while (a.x < game->map.width * 50)
	{
		while (a.y < game->map.height * 50)
		{
			if (game->map.tab[a.y / 50][a.x / 50] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
										a.x, a.y);
			else if (game->map.tab[a.y / 50][a.x / 50] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->start.img,
										a.x, a.y);
			else if (game->map.tab[a.y / 50][a.x / 50] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->steak.img,
										a.x, a.y);
			else if (game->map.tab[a.y / 50][a.x / 50] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
										a.x, a.y);
			a.y += 50;
		}
		a.y = 0;
		a.x += 50;
	}
}

void cat_print(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->cat_sp.img,
							game->cat.pos.x * 50, game->cat.pos.y * 50);
}

int all_print(t_game *game)
{
	bg_print(game);
	if (!game->end)
	{
		map_print(game);
		cat_print(game);
		// draw_moves(vars);
	}
	// else
	// {
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->yw_sp.img, 0, 0);
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
	// 							(vars->moves / 100)].img, 1 * SIZE + 10, \
	// 														3 * SIZE + 10);
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
	// 							(vars->moves / 10) % 10].img, 2 * SIZE + 10, \
	// 														3 * SIZE + 10);
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
	// 							(vars->moves % 100) % 10].img, 3 * SIZE + 10, \
	// 														3 * SIZE + 10);
	// }
	return (0);
}
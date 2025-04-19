#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
	{
		m_error("Il faut une map !!!");
		return (1);
	}
	else if (argc > 2)
	{
		m_error("Il y a trop d'arguments :/");
		return (1);
	}
	else if (map_name(argv[1]))
		m_error("Il faut un fichier .ber !!!");
	game_init(&game, argv[1]);
	map_check(&game.map);
	map_init(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 50, game.map.height * 50, "so_long");
	game.img.img = mlx_new_image(game.mlx, game.map.width * 50, game.map.height * 50);
	game.img.adr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
			&game.img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// draw_square(&img, 50, 50, 100, 0x00FF0000);
	// draw_circle(&img, 200, 200, 50, 0x0000FF00);
	// draw_triangle(&img, 400, 100, 60, 0x000000FF);
	// draw_hexagon(&img, 600, 200, 50, 0x00FFFF00);
	// draw_horizontal_gradient(&img, 50, 200, 300, 50);
	// draw_rainbow(&img, 400, 200, 300);
	// draw_checkerboard(&img, 800, 600, 40);
	mlx_loop(game.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

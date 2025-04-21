#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		m_error("Il faut une map !!!");
	else if (argc > 2)
		m_error("Il y a trop d'arguments :/");
	else if (map_name(argv[1]))
		m_error("Il faut un fichier .ber !!!");
	game_init(&game, argv[1]);
	map_check(&game.map);
	map_init(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 50, game.map.height
			* 50, "./so_long");
	game.img.img = mlx_new_image(game.mlx, game.map.width * 50, game.map.height
			* 50);
	game.img.adr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_length, &game.img.endian);
	sprite_init(&game);
	mlx_hook(game.win, 17, 1L << 0, close_win, &game);
	mlx_loop_hook(game.mlx, all_print, &game);
	mlx_loop(game.mlx);
	return (0);
}

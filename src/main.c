/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:49 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:50 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	texture_init(&game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_key_hook(game.win, key_event, &game);
	bg_print(&game);
	mlx_loop_hook(game.mlx, all_print, &game);
	mlx_loop(game.mlx);
	return (0);
}

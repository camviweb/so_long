/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:12 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:14 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *mapfile)
{
	game->map.mapfile = mapfile;
	game->map.start_nb = 0;
	game->map.exit_nb = 0;
	game->map.steak_nb = 0;
	game->map.available_exit = 0;
	game->map.available_steaks = 0;
	game->end = 0;
	game->move_nb = 0;
	game->steak_won = 0;
	game->exit_is_open = 0;
}

void	update_cat_pos(t_game *game, t_point pos)
{
	game->move_nb++;
	ft_printf("Nombre de mouvements : %d\n", game->move_nb);
	if (pos.x < game->map.width && pos.y < game->map.height)
	{
		if (game->map.tab[pos.y][pos.x] == 'C')
		{
			game->steak_won++;
			game->map.tab[pos.y][pos.x] = '0';
			if (game->steak_won == game->map.steak_nb)
				game->exit_is_open = 1;
			game->cat.pos = pos;
		}
		else if (game->map.tab[pos.y][pos.x] == 'E' && game->exit_is_open)
		{
			game->cat.pos = pos;
			game->end = 1;
		}
		else if (game->map.tab[pos.y][pos.x] != '1')
			game->cat.pos = pos;
	}
}

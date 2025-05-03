/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:38:59 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:05 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->start.img);
	mlx_destroy_image(game->mlx, game->cat_sp.img);
	mlx_destroy_image(game->mlx, game->steak.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->bg.img);
	mlx_destroy_image(game->mlx, game->yw.img);
	free_tile(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	key_event(int kcode, t_game *game)
{
	if (kcode == 53 || kcode == 65307)
		close_win(game);
	else if ((kcode == 2 || kcode == 100) && !game->end)
		update_cat_pos(game, (t_point){game->cat.pos.x + 1, game->cat.pos.y});
	else if ((kcode == 0 || kcode == 97) && !game->end)
		update_cat_pos(game, (t_point){game->cat.pos.x - 1, game->cat.pos.y});
	else if ((kcode == 13 || kcode == 119) && !game->end)
		update_cat_pos(game, (t_point){game->cat.pos.x, game->cat.pos.y - 1});
	else if ((kcode == 1 || kcode == 115) && !game->end)
		update_cat_pos(game, (t_point){game->cat.pos.x, game->cat.pos.y + 1});
	return (0);
}

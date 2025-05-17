/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:22:51 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/17 17:22:54 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tail_at(t_game *game, t_point a)
{
	if (game->map.tab[a.y / 50][a.x / 50] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img, \
			a.x, a.y);
	else if (game->map.tab[a.y / 50][a.x / 50] == 'P'
			&& (game->cat.pos.x != a.x / 50 || game->cat.pos.y != a.y
				/ 50))
		mlx_put_image_to_window(game->mlx, game->win, game->start.img, \
			a.x, a.y);
	else if (game->map.tab[a.y / 50][a.x / 50] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->steak.img, \
			a.x, a.y);
	else if (game->map.tab[a.y / 50][a.x / 50] == 'E'
			&& (game->cat.pos.x != a.x / 50 || game->cat.pos.y != a.y
				/ 50))
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img, \
			a.x, a.y);
	else if ((game->map.tab[a.y / 50][a.x / 50] == '0')
			&& (game->cat.pos.x != a.x / 50 || game->cat.pos.y != a.y
				/ 50))
		mlx_put_image_to_window(game->mlx, game->win, \
			game->bg.img, a.x, a.y);
}

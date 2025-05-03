/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:58 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:40:00 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_init(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "texture/wall_bg.xpm",
			&game->wall.w, &game->wall.h);
	game->start.img = mlx_xpm_file_to_image(game->mlx, "texture/start_bg.xpm",
			&game->start.w, &game->start.h);
	game->cat_sp.img = mlx_xpm_file_to_image(game->mlx, "texture/cat_bg.xpm",
			&game->cat_sp.w, &game->cat_sp.h);
	game->steak.img = mlx_xpm_file_to_image(game->mlx, "texture/steak_bg.xpm",
			&game->steak.w, &game->steak.h);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "texture/exit_bg.xpm",
			&game->exit.w, &game->exit.h);
	game->bg.img = mlx_xpm_file_to_image(game->mlx, "texture/background.xpm",
			&game->bg.w, &game->bg.h);
	game->yw.img = mlx_xpm_file_to_image(game->mlx, "texture/yw_bg.xpm",
			&game->yw.w, &game->yw.h);
}

void	bg_print(t_game *game)
{
	t_point	a;
	t_point	m;

	a.x = 0;
	a.y = 0;
	m.x = game->map.width * 50;
	// ft_printf("%d\n", game->map.width);
	m.y = game->map.height * 50;
	while (a.x < m.x)
	{
		while (a.y < m.y)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->bg.img, a.x, a.y);
			a.y += 50;
		}
		a.y = 0;
		a.x += 50;
	}
}

void	map_print(t_game *game)
{
	t_point	a;

	a.x = 0;
	a.y = 0;
	while (a.x < game->map.width * 50)
	{
		while (a.y < game->map.height * 50)
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
				mlx_put_image_to_window(game->mlx, game->win, game->bg.img, a.x, \
					a.y);
			a.y += 50;
		}
		a.y = 0;
		a.x += 50;
	}
}

void	cat_print(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->cat_sp.img, game->cat.pos.x * 50, game->cat.pos.y * 50);
}

int	all_print(t_game *game)
{
	t_point	a;

	if (!game->end)
	{
		map_print(game);
		cat_print(game);
	}
	else
	{
		a.x = 0;
		a.y = 0;
		while (a.x < game->map.width * 50)
		{
			while (a.y < game->map.height * 50)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->yw.img, a.x, a.y);
				a.y += 50;
			}
			a.y = 0;
			a.x += 50;
		}
	}
	return (0);
}

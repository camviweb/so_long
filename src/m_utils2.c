/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:31 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:35 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(t_map *map)
{
	t_point	a;

	a.y = 0;
	a.x = 0;
	while (a.y < map->height)
	{
		while (a.x < map->width)
		{
			ft_printf("%c", map->tab[a.y][a.x]);
			a.x++;
		}
		write(1, "\n", 1);
		a.x = 0;
		a.y++;
	}
}

void	tile_count(t_game *game, char c, t_point pos)
{
	if (c == 'P')
	{
		game->map.start_nb++;
		game->cat.start = pos;
		game->cat.pos = pos;
	}
	else if (c == 'E')
		game->map.exit_nb++;
	else if (c == 'C')
		game->map.steak_nb++;
}

void	print_s_map(t_map *map)
{
	ft_printf("mapfile : %s\n", map->mapfile);
	ft_printf("fd : %d\n", map->fd);
	ft_printf("width : %d\n", map->width);
	ft_printf("height : %d\n", map->height);
	print_tab(map);
	ft_printf("start_nb : %d\n", map->start_nb);
	ft_printf("exit_nb : %d\n", map->exit_nb);
	ft_printf("steak_nb : %d\n", map->steak_nb);
}

int	is_closed(t_map *map)
{
	t_point	a;

	a.y = 0;
	a.x = 0;
	while (a.y < map->height)
	{
		if (map->tab[a.y][a.x] != '1')
			return (1);
		if (map->tab[a.y][map->width - 1] != '1')
			return (1);
		a.y++;
	}
	a.y = 0;
	while (a.x < map->width)
	{
		if (map->tab[a.y][a.x] != '1')
			return (1);
		if (map->tab[map->height - 1][a.x] != '1')
			return (1);
		a.x++;
	}
	return (0);
}

void	tile_check(t_map *map)
{
	if (map->start_nb == 0)
		m_error("La map doit avoir un debut !!!");
	if (map->start_nb > 1)
		m_error("La map a plusieurs debuts :/");
	if (map->exit_nb == 0)
		m_error("La map doit avoir une sortie !!!");
	if (map->exit_nb > 1)
		m_error("La map a plusieurs sorties :/");
	if (map->steak_nb == 0)
		m_error("La map doit avoir au moins un steak !!!");
	// if (!map->available_exit)
	// 	m_error("La sortie est inacessible :/");
	// if (map->available_steaks != map->steak_nb)
	// 	m_error("Il n'y a pas de chemins pour recuperer tous les steaks :/");
}

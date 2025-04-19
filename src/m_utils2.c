#include "so_long.h"

void	print_tab(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			ft_printf("%c", map->tab[i][j]);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
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
	ft_printf("height : %d\n", map->height);
	ft_printf("width : %d\n", map->width);
	print_tab(map);
	ft_printf("start_nb : %d\n", map->start_nb);
	ft_printf("exit_nb : %d\n", map->exit_nb);
	ft_printf("steak_nb : %d\n", map->steak_nb);
}

int	is_closed(t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (x < map->height)
	{
		if (map->tab[x][y] != '1')
			return (1);
		if (map->tab[x][map->width - 1] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < map->width)
	{
		if (map->tab[x][y] != '1')
			return (1);
		if (map->tab[map->height - 1][y] != '1')
			return (1);
		y++;
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
		m_error("La map doit avoir une croquette !!!");
	// if (!vars->map.exit_accessible)
	// 	map_error("No valid path to exit.");
	// if (vars->map.accessible_collectibles != vars->collectibles)
	// 	map_error("No path to all collectibles.");
}
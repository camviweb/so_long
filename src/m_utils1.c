#include "so_long.h"

// void check_map(const char *filename, t_game *game);

void	map_check(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->mapfile, O_RDONLY);
	if (fd < 0)
		m_error("Fichier introuvable :/");
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->height == 1)
			map->width = linelen(line);
		if (linelen(line) != map->width)
			m_error("La map doit etre rectangulaire !!!");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		m_error("La map est vide :/");
}

void	m_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

int	map_name(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (0);
	return (1);
}

int	linelen(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

void	map_init(t_game *game)
{
	t_point	pos;
	char	*line;

	game->map.fd = open(game->map.mapfile, O_RDONLY);
	game->map.tab = malloc(game->map.height * sizeof(char *));
	pos.x = 0;
	pos.y = 0;
	line = get_next_line(game->map.fd);
	while (line)
	{
		// map->width - 1 ??
		game->map.tab[pos.x] = malloc(game->map.width * sizeof(char));
		while (pos.y < game->map.width)
		{
			game->map.tab[pos.x][pos.y] = line[pos.y];
			tile_count(game, game->map.tab[pos.x][pos.y] = line[pos.y], pos);
			pos.y++;
		}
		pos.x++;
		pos.y = 0;
		line = get_next_line(game->map.fd);
	}
	print_s_map(&game->map);
	close(game->map.fd);
	if (is_closed(&game->map))
		m_error("La map doit etre fermee !!!");
	tile_check(&game->map);
}

// int	fill_grid(t_vars *vars)
// {
// 	// t_point g_pos;
// 	// char *line;

// 	// initiate_map_filling(vars, &g_pos);
// 	// line = get_next_line(vars->map.fd);
// 	while (line)
// 	{
// 		allocate_line(vars, g_pos);
// 		while (g_pos.px_x < vars->map.g_w)
// 		{
// 			fill_tiles(vars, line, g_pos);
// 			// count_grid(vars, vars->map.grid[g_pos.px_y][g_pos.px_x], g_pos);
// 			// g_pos.px_x++;
// 		}
// 		// g_pos.px_x = 0;
// 		// g_pos.px_y++;
// 		// line = get_next_line(vars->map.fd);
// 	}
// 	// close(vars->map.fd);
// 	// if (walls_error(vars))
// 	// 	map_error("Map not enclosed in walls.");
// 	check_path(vars->player.pos, vars);
// 	check_map(vars);
// 	return (1);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:24 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:26 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->mapfile, O_RDONLY);
	if (fd < 0)
		m_error("Fichier introuvable :/");
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->height == 1)
			map->width = linelen(line);
		if (linelen(line) != map->width)
			m_error("La map doit etre rectangulaire !!!");
		ft_free(&line, 0, 0);
		line = get_next_line(fd);
	}
	ft_free(&line, 0, 0);
	close(fd);
	if (map->height == 0)
		m_error("La map est vide :/");
}

void	m_error(char *s)
{
	write(1, "Error\n", 6);
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

	map_init_helper(game);
	line = get_next_line(game->map.fd);
	while (line)
	{
		line_alloc(game, pos);
		while (pos.x < game->map.width)
		{
			fill_tabs(game, &line, pos);
			tile_count(game, game->map.tab[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
		ft_free(&line, 0, 0);
		line = get_next_line(game->map.fd);
	}
	ft_free(&line, 0, 0);
	close(game->map.fd);
	if (is_closed(&game->map))
		m_error_with_tab("La map doit etre fermee !!!", game);
	valid_path_checker(game->cat.pos, game);
	tile_check(game);
}

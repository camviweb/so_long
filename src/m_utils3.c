/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:38 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:39:41 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tile(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.tab[i])
			free(game->map.tab[i]);
		if (game->map.tab2[i])
			free(game->map.tab2[i]);
		i++;
	}
	if (game->map.tab)
	{
		free(game->map.tab);
		game->map.tab = NULL;
	}
	if (game->map.tab2)
	{
		free(game->map.tab2);
		game->map.tab2 = NULL;
	}
}

void	map_init_helper(t_game *game)
{
	int	i;

	i = 0;
	game->map.fd = open(game->map.mapfile, O_RDONLY);
	game->map.tab = malloc(game->map.height * sizeof(char *));
	if (!game->map.tab)
		m_error_with_tab("Allocation echoue", game);
	game->map.tab2 = malloc(game->map.height * sizeof(char *));
	if (!game->map.tab2)
		m_error_with_tab("Allocation echoue", game);
	while (i < game->map.height)
	{
		game->map.tab[i] = NULL;
		game->map.tab2[i] = NULL;
		i++;
	}
}

void	valid_path_checker(t_point pos, t_game *game)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > game->map.width - 1
		|| pos.y > game->map.height - 1 || game->map.tab2[pos.y][pos.x] == '1')
		return ;
	if (game->map.tab[pos.y][pos.x] == 'E')
		game->map.available_exit = 1;
	if (game->map.tab[pos.y][pos.x] == 'C')
		game->map.available_steaks++;
	game->map.tab2[pos.y][pos.x] = '1';
	valid_path_checker((t_point){pos.x - 1, pos.y}, game);
	valid_path_checker((t_point){pos.x + 1, pos.y}, game);
	valid_path_checker((t_point){pos.x, pos.y - 1}, game);
	valid_path_checker((t_point){pos.x, pos.y + 1}, game);
}

void	fill_tabs(t_game *game, char **line, t_point pos)
{
	if ((*line)[pos.x] != 'C' && (*line)[pos.x] != 'P' && (*line)[pos.x] != 'E' \
		&& (*line)[pos.x] != '1' && (*line)[pos.x] != '0')
	{
		ft_free(line, 0, 0);
		close(game->map.fd);
		m_error_with_tab("Caractere inconnu dans la map :/", game);
	}
	game->map.tab[pos.y][pos.x] = (*line)[pos.x];
	game->map.tab2[pos.y][pos.x] = (*line)[pos.x];
}

void	line_alloc(t_game *game, t_point pos)
{
	int	i;

	i = 0;
	game->map.tab[pos.y] = malloc(game->map.width * sizeof(char));
	if (!game->map.tab[pos.y])
		m_error_with_tab("Allocation echoue", game);
	game->map.tab2[pos.y] = malloc(game->map.width * sizeof(char));
	if (!game->map.tab2[pos.y])
		m_error_with_tab("Allocation echoue", game);
	while (i < game->map.height)
	{
		game->map.tab[pos.y][i] = 0;
		game->map.tab2[pos.y][i] = 0;
		i++;
	}
}

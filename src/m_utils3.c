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
		free(game->map.tab[i]);
		game->map.tab[i] = NULL;
		i++;
	}
	free(game->map.tab);
	game->map.tab = NULL;
}

void	map_init_helper(t_game *game, t_point *pos)
{
	pos->x = 0;
	pos->y = 0;
	game->map.fd = open(game->map.mapfile, O_RDONLY);
	game->map.tab = malloc(game->map.height * sizeof(char *));
}

void	valid_path_checker(t_point pos, t_game *game)
{
	if (game->map.tab[pos.y][pos.x] == '1' || pos.x < 0 || pos.y < 0
		|| pos.x > game->map.width || pos.y > game->map.height)
		return ;
	if (game->map.tab[pos.y][pos.x] == 'E')
		game->map.available_exit = 1;
	if (game->map.tab[pos.y][pos.x] == 'C')
		game->map.available_steaks++;
	valid_path_checker((t_point){pos.x - 1, pos.y}, game);
	valid_path_checker((t_point){pos.x + 1, pos.y}, game);
	valid_path_checker((t_point){pos.x, pos.y - 1}, game);
	valid_path_checker((t_point){pos.x, pos.y + 1}, game);
}

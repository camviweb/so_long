/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:42:56 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/24 11:43:00 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_error_with_tab(char *s, t_game *game)
{
	free_tile(game);
	write(1, "Error\n", 6);
	ft_printf("%s\n", s);
	exit(1);
}

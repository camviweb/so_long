/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:47:48 by canguyen          #+#    #+#             */
/*   Updated: 2025/05/03 14:47:50 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_img
{
	void		*img;
	char		*adr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_cat
{
	t_point		pos;
}				t_cat;

typedef struct s_sprite
{
	int			h;
	int			w;
	void		*img;
}				t_sprite;

typedef struct s_map
{
	char		*mapfile;
	int			fd;
	int			width;
	int			height;
	char		**tab;
	char		**tab2;
	int			start_nb;
	int			exit_nb;
	int			steak_nb;
	int			available_exit;
	int			available_steaks;
}				t_map;

typedef struct s_game
{
	t_map		map;
	t_cat		cat;
	void		*mlx;
	void		*win;
	t_img		img;
	t_sprite	wall;
	t_sprite	start;
	t_sprite	cat_sp;
	t_sprite	steak;
	t_sprite	exit;
	t_sprite	bg;
	t_sprite	yw;
	int			end;
	int			move_nb;
	int			steak_won;
	int			exit_is_open;
}				t_game;

#endif

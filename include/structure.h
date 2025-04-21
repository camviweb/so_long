#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_img
{
	void	*img;
	char	*adr;
	int		bits_per_pixel;
	int line_length; // ?
	int endian;      // ?
}			t_img;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_cat
{
	t_point		pos;
	t_point		start;
	// t_sprite	sprite;
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
	int			start_nb;
	int			exit_nb;
	int			steak_nb;
	// t_tile		**tiles;
	// int			exit_accessible;
	// int			accessible_collectibles;
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
	int			end;
	int			move_nb;
	// t_sprite	*digits_sp;
	// int			collected;
	// BOOL		exit_unlocked;
}				t_game;

#endif
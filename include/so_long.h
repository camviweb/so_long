#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "structure.h"
# include <fcntl.h> // open
# include <math.h>
# include <mlx.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// form
void	draw_square(t_img *img, int x, int y, int size, int color);
void	draw_circle(t_img *img, int x_center, int y_center, int radius,
			int color);
void	draw_triangle(t_img *img, int x, int y, int size, int color);
void	draw_hexagon(t_img *img, int x_center, int y_center, int size,
			int color);

// color
int		create_trgb(int t, int r, int g, int b);
void	draw_horizontal_gradient(t_img *img, int x, int y, int width,
			int height);
void	draw_rainbow(t_img *img, int x, int y, int width);

// texture
void	draw_checkerboard(t_img *img, int width, int height, int size);

// m_utils1
void	map_check(t_map *map);
void	m_error(char *s);
int		map_name(char *s);
int		linelen(char *s);
void	map_init(t_game *game);

// m_utils2
void	print_tab(t_map *map);
void	tile_count(t_game *game, char c, t_point pos);
void	print_s_map(t_map *map);
int		is_closed(t_map *map);
void	tile_check(t_map *map);

// s_utils1

// game
void	game_init(t_game *game, char *mapfile);

#endif
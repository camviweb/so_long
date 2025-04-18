#ifndef SO_LONG_H
# define SO_LONG_H
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int line_length; // ?
	int endian;      // ?
}			t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

// form
void		draw_square(t_data *img, int x, int y, int size, int color);
void		draw_circle(t_data *img, int x_center, int y_center, int radius,
				int color);
void		draw_triangle(t_data *img, int x, int y, int size, int color);
void		draw_hexagon(t_data *img, int x_center, int y_center, int size,
				int color);

// color
int			create_trgb(int t, int r, int g, int b);
void		draw_horizontal_gradient(t_data *img, int x, int y, int width,
				int height);
void		draw_rainbow(t_data *img, int x, int y, int width);

// texture
void		draw_checkerboard(t_data *img, int width, int height, int size);

#endif
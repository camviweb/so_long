#include "so_long.h"

int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_horizontal_gradient(t_data *img, int x, int y, int width,
		int height)
{
	int	red;
	int	blue;
	int	color;

	for (int i = 0; i < width; i++)
	{
		red = 255 - (i * 255 / width);
		blue = (i * 255 / width);
		color = rgb(red, 0, blue);
		for (int j = 0; j < height; j++)
			my_mlx_pixel_put(img, x + i, y + j, color);
	}
}

void	draw_rainbow(t_data *img, int x, int y, int width)
{
	float	t;
	int		r;
	int		g;
	int		b;
	int		color;

	for (int i = 0; i < width; i++)
	{
		t = (float)i / width;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color = rgb(r, g, b);
		for (int j = 0; j < 50; j++)
			my_mlx_pixel_put(img, x + i, y + j, color);
	}
}
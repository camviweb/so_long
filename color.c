#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
		color = create_trgb(0, red, 0, blue);
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
		color = create_trgb(t, r, g, b);
		for (int j = 0; j < 50; j++)
			my_mlx_pixel_put(img, x + i, y + j, color);
	}
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

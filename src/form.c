#include "so_long.h"

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
		}
	}
}

void	draw_circle(t_img *img, int x_center, int y_center, int radius,
		int color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(img, x_center + x, y_center + y, color);
		}
	}
}

void	draw_triangle(t_img *img, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			my_mlx_pixel_put(img, x + j, y + i, color);
		}
	}
}

void	draw_hexagon(t_img *img, int x_center, int y_center, int size,
		int color)
{
	float	angle;

	int x, y;
	for (int i = 0; i < 360; i++)
	{
		angle = i * M_PI / 180;
		x = (int)(x_center + size * cos(angle));
		y = (int)(y_center + size * sin(angle));
		my_mlx_pixel_put(img, x, y, color);
	}
}
#include "so_long.h"

void	draw_checkerboard(t_img *img, int width, int height, int size)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (((x / size) + (y / size)) % 2 == 0)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF); 
			else
				my_mlx_pixel_put(img, x, y, 0x00000000);
		}
	}
}
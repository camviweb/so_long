#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc == 1)
		return (1);
	// fd_map
	if (argv[1] != 0)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		draw_square(&img, 50, 50, 100, 0x00FF0000);
		draw_circle(&img, 200, 200, 50, 0x0000FF00);
		draw_triangle(&img, 400, 100, 60, 0x000000FF);
		draw_hexagon(&img, 600, 200, 50, 0x00FFFF00);
		draw_horizontal_gradient(&img, 50, 200, 300, 50);
		draw_rainbow(&img, 400, 200, 300);
		// draw_checkerboard(&img, 800, 600, 40);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

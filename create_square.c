#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    create_square(t_win *map)
{
	t_data	*img;
    int y;
    int x;

	img = (t_data *)malloc(sizeof(t_data));
    //if the t_data is not alloc'ed, would it be saved? is it malloced as part of t_win in main? 
    y = x = 0;
    img->img = mlx_new_image(map->mlx_ptr, TILE_SIDE, TILE_SIDE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    while (y++ < TILE_SIDE * 0.96)
	{
		while (x++ < TILE_SIDE * 0.96)
			my_mlx_pixel_put(img, x, y, 0x2F2E2F);
		x = 0;
	}
    map->dimg = img;
}
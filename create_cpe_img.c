#include "so_long.h"

void    put_pixel_img(t_data *img, int x, int y, int color)
{
    char    *dst;

    if (color == (int)0xFF000000)
        return ;
    if (x >= 0 && y >= 0 && x < TILE_SIDE && y < TILE_SIDE)
    {
        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

unsigned int    get_pixel_img(t_data *img, int x, int y)
{
    return (*(unsigned int *)((img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8))));
}

void    put_img_to_img(t_data *dst, t_data *src, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIDE)
    {
        j = 0;
        while (j < TILE_SIDE)
        {
            put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
            j++;
        }
        i++;
    }
}

void    create_collectible(t_win *map)
{
	t_data	*c_img;
    //int y;
    //int x;

	c_img = (t_data *)malloc(sizeof(t_data));
//    y = x = 0;
    c_img->img = mlx_xpm_file_to_image(map->mlx_ptr, C_PATH, &(map->img_width), &(map->img_height));
	c_img->addr = mlx_get_data_addr(c_img->img, &c_img->bits_per_pixel,
            &c_img->line_length, &c_img->endian);
    map->c_img = c_img;
    //put_img_to_img(c_img, map->dimg, x, y); 
}
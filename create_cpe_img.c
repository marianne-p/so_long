#include "so_long.h"

/*void    put_pixel_img(t_data *img, int x, int y, int color)
{
    char    *dst;

    //printf("%d, ", color);
    //printf("Img address in put_pixel_img: %p\n", img->addr);
    //printf("Color received in put_pixel_img: %d\n", color);
    if (color == (int)0xFF000000)
    {
        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)dst = 0x2F2E2F;
        //printf("OTHER\n");
    }
    else
        return ;
}*/

unsigned int    get_pixel_img(t_data *img, int x, int y)
{
    return (*(unsigned int *)((img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8))));
}

void    put_img_to_img(t_data *img, int x, int y)
{
    int i;
    int j;
    char    *dst;

//    printf("SRC address in put_img_to_img: %p\n", src->addr);
//    printf("DST address in put_img_to_img: %p\n", dst->addr);
    i = 0;
    while (i < TILE_SIDE)
    {
        j = 0;
        while (j < TILE_SIDE)
        {
            if (get_pixel_img(img, i, j) == (unsigned int)0xFF000000)
            {
                dst = img->addr + ((y + j) * img->line_length + (x + i) * (img->bits_per_pixel / 8));
                *(unsigned int *)dst = 0x2F2E2F;
            }
            j++;
        }
        i++;
    }
}

void    create_collectible(t_win *map)
{
	t_data	*c_img;
    int y;
    int x;

	c_img = (t_data *)malloc(sizeof(t_data));
    y = x = 0;
    c_img->img = mlx_xpm_file_to_image(map->mlx_ptr, C_PATH, &(map->img_width), &(map->img_height));
	c_img->addr = mlx_get_data_addr(c_img->img, &c_img->bits_per_pixel,
            &c_img->line_length, &c_img->endian);
//    printf("%p\n%p\n", c_img->addr, map->dimg->addr);
    put_img_to_img(c_img, x, y); 
    map->c_img = c_img;
}
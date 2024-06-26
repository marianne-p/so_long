/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cpe_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:07 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 16:15:08 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	put_pixel_img(t_data *img, int x, int y, int color)
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

unsigned int	get_pixel_img(t_data *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_length)
			+ (x * img->bits_per_pixel / 8))));
}

void	put_img_to_img(t_data *img, int x, int y)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < TILE_SIDE)
	{
		j = 0;
		while (j < TILE_SIDE)
		{
			if (get_pixel_img(img, i, j) == (unsigned int)0xFF000000)
			{
				dst = img->addr + ((y + j) * img->line_length
						+ (x + i) * (img->bits_per_pixel / 8));
				*(unsigned int *)dst = 0x2F2E2F;
			}
			j++;
		}
		i++;
	}
}

static void	images(t_data *p_img, t_data *flower_img,
		t_data *exit_img, t_win *map)
{
	p_img->img = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER_PATH,
			&(map->img_width), &(map->img_height));
	p_img->addr = mlx_get_data_addr(p_img->img, &p_img->bits_per_pixel,
			&p_img->line_length, &p_img->endian);
	flower_img->img = mlx_xpm_file_to_image(map->mlx_ptr, FLOWER_PATH,
			&(map->img_width), &(map->img_height));
	flower_img->addr = mlx_get_data_addr(flower_img->img,
			&flower_img->bits_per_pixel, &flower_img->line_length,
			&flower_img->endian);
	exit_img->img = mlx_xpm_file_to_image(map->mlx_ptr, EXIT_PATH,
			&(map->img_width), &(map->img_height));
	exit_img->addr = mlx_get_data_addr(exit_img->img, &exit_img->bits_per_pixel,
			&exit_img->line_length, &exit_img->endian);
	put_img_to_img(p_img, 0, 0);
	put_img_to_img(flower_img, 0, 0);
	put_img_to_img(exit_img, 0, 0);
	map->p_img = p_img;
	map->flower_img = flower_img;
	map->exit_img = exit_img;
}

void	create_collectible(t_win *map)
{
	t_data	*p_img;
	t_data	*flower_img;
	t_data	*exit_img;

	p_img = (t_data *)malloc(sizeof(t_data));
	flower_img = (t_data *)malloc(sizeof(t_data));
	exit_img = (t_data *)malloc(sizeof(t_data));
	map->enemy_fst = (t_data *)malloc(sizeof(t_data));
	map->enemy_snd = (t_data *)malloc(sizeof(t_data));
	if (p_img == NULL || flower_img == NULL || exit_img == NULL || map->enemy_fst == NULL || map->enemy_snd == NULL)
		return ;
	images(p_img, flower_img, exit_img, map);
	map->enemy_fst->img = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY_1,
			&(map->img_width), &(map->img_height));
	map->enemy_fst->addr = mlx_get_data_addr(map->enemy_fst->img, &map->enemy_fst->bits_per_pixel,
			&map->enemy_fst->line_length, &map->enemy_fst->endian);
	map->enemy_snd->img = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY_2,
			&(map->img_width), &(map->img_height));
	map->enemy_snd->addr = mlx_get_data_addr(map->enemy_snd->img, &map->enemy_snd->bits_per_pixel,
			&map->enemy_snd->line_length, &map->enemy_snd->endian);
	put_img_to_img(map->enemy_fst, 0, 0);
	put_img_to_img(map->enemy_snd, 0, 0);
}

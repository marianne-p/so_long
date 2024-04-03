/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:25:35 by mpihur            #+#    #+#             */
/*   Updated: 2024/04/03 17:25:37 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    update_enemy(t_win **map_ptr)
{
    if ((*map_ptr)->frm % 2 == 0)
    {
        (*map_ptr)->frm++;
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->enemy_fst->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
    }
    else
    {
        (*map_ptr)->frm++;
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->enemy_snd->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
    }
}

int    put_more_img(t_win **map_ptr, t_list *head, size_t i)
{
	if ((ft_strncmp((&((char *)head->content)[i]), "P", 1)) == 0)
    {
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->p_img->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
        return (1);
    }
	if ((ft_strncmp((&((char *)head->content)[i]), "C", 1)) == 0)
    {
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->flower_img->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
        return (1);
    }
	if ((ft_strncmp((&((char *)head->content)[i]), "N", 1)) == 0)
    {
		update_enemy(map_ptr);
        return (1);
    }
    return (0);
}
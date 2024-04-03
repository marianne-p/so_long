/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:00:28 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/30 13:19:55 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_enemy(t_win *map)
{
	mlx_destroy_image(map->mlx_ptr, map->enemy_fst->img);
	mlx_destroy_image(map->mlx_ptr, map->enemy_snd->img);
	free(map->enemy_fst);
	free(map->enemy_snd);
}

int	close_win(void *param)
{
	t_win	*map;

	map = param;
	mlx_destroy_image(map->mlx_ptr, map->wall_img_ptr);
	mlx_destroy_image(map->mlx_ptr, map->dimg->img);
	mlx_destroy_image(map->mlx_ptr, map->p_img->img);
	mlx_destroy_image(map->mlx_ptr, map->flower_img->img);
	mlx_destroy_image(map->mlx_ptr, map->exit_img->img);
	free_enemy(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	ft_lstclear(&(map->exit_cpy), free);
	ft_lstclear(map->head_ptr, free);
//	free(map->wall_img_ptr);
	free(map->dimg);
	free(map->p_img);
	free(map->flower_img);
	free(map->exit_img);
	free(map);
	exit (1);
}

int	handle_error_and_free(char *error, int ernum, t_win *map)
{
	mlx_destroy_image(map->mlx_ptr, map->dimg->img);
	mlx_destroy_image(map->mlx_ptr, map->p_img->img);
	mlx_destroy_image(map->mlx_ptr, map->flower_img->img);
	mlx_destroy_image(map->mlx_ptr, map->exit_img->img);
	free_enemy(map);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	//ft_lstclear(&(map->exit_cpy), free);
	ft_lstclear(map->head_ptr, free);
	free(map->dimg);
	free(map->p_img);
	free(map->flower_img);
	free(map->exit_img);
	free(map);
	perror(error);
	return (ernum);
}
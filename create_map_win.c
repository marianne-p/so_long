#include "so_long.h"
 
 void	*window_image(t_win **map_ptr)
 {
	(*map_ptr)->win_ptr = mlx_new_window((*map_ptr)->mlx_ptr, (*map_ptr)->width, (*map_ptr)->height, "so_long");
	if ((*map_ptr)->win_ptr == NULL)
	{
		mlx_destroy_display((*map_ptr)->mlx_ptr);
		free((*map_ptr)->mlx_ptr);
		return (NULL);
		// is other stuff free after receiving NULL in main?
	}
	(*map_ptr)->wall_img_ptr = mlx_xpm_file_to_image((*map_ptr)->mlx_ptr, WALL_XPM_PATH,
		&((*map_ptr)->img_width), &((*map_ptr)->img_height));
	if ((*map_ptr)->wall_img_ptr == NULL)
	{
		mlx_destroy_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr);
		mlx_destroy_display((*map_ptr)->mlx_ptr);
		free((*map_ptr)->mlx_ptr);
		return (NULL);
	}
	return (*map_ptr);
 }

void	*put_images_to_win(t_win **map_ptr, t_list *head, int height_now, int width_now)
{
	size_t	i;
	//t_list	*head;
	const char	ch[5] = "1PCE0";

	i = 0;
	//head = (*(*map_ptr)->head_ptr);
	while (height_now < (*map_ptr)->height)
	{
		while (width_now < (*map_ptr)->width && i < ft_strlen((char *)head->content) - 1)
		{
			if ((ft_strncmp((&((char *)head->content)[i]), &ch[0], 1)) == 0)
			{
				mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr, (*map_ptr)->wall_img_ptr, width_now, height_now);
			}
			else if ((ft_strncmp((&((char *)head->content)[i]), &ch[1], 1)) == 0)
				mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr, (*map_ptr)->p_img->img, width_now, height_now);
			else if ((ft_strncmp((&((char *)head->content)[i]), &ch[2], 1)) == 0)
				mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr, (*map_ptr)->flower_img->img, width_now, height_now);
			else if ((ft_strncmp((&((char *)head->content)[i]), &ch[3], 1)) == 0)
				mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr, (*map_ptr)->exit_img->img, width_now, height_now);
			else
				mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr, (*map_ptr)->dimg->img, width_now, height_now);
			i++;
			width_now += TILE_SIDE;
		}
		i = 0;
		head = head->next;
		width_now = 0;
		height_now += TILE_SIDE;
	}
	return (map_ptr);
}

int	close_win(void *param)
{	
	t_win *map;

	map = param;
	mlx_destroy_image(map->mlx_ptr, map->wall_img_ptr);
	mlx_destroy_image(map->mlx_ptr, map->dimg->img);
	mlx_destroy_image(map->mlx_ptr, map->p_img->img);
	mlx_destroy_image(map->mlx_ptr, map->flower_img->img);
	mlx_destroy_image(map->mlx_ptr, map->exit_img->img);
	//destroy other imgs
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	//ft_printf("Pointer to head %p\n", map->head_ptr);
	ft_lstclear(map->head_ptr, free);
	free(map->dimg);
	free(map->p_img);
	free(map->flower_img);
	free(map->exit_img);
	free(map);
	exit (1); //add FREEs if more alloc's done!
}

int	handle_keys(int keysum, void *param)
{
	if (keysum == XK_Escape)
	{
		close_win(param);
		exit (1);
	}
	if (keysum == XK_w || keysum == XK_Up)
		put_images_to_win((t_win **)&param, check_and_change(((t_win *)param), 4, NULL, NULL), 0, 0);
	//move up
	if (keysum == XK_s || keysum == XK_Down)
		put_images_to_win((t_win **)&param, check_and_change(((t_win *)param), 3, NULL, NULL), 0, 0);
	//move down
	if (keysum == XK_a || keysum == XK_Left)
		put_images_to_win((t_win **)&param, check_and_change(((t_win *)param), 2, NULL, NULL), 0, 0);
		//move left
	if (keysum == XK_d || keysum == XK_Right)
		put_images_to_win((t_win **)&param, check_and_change(((t_win *)param), 1, NULL, NULL), 0, 0);
		//move right*
	return (0);
}

void	create_map_win(t_win **map_ptr, t_list **head_ptr)
{
	(*map_ptr)->width = TILE_SIDE * (ft_strlen((char *)(*head_ptr)->content) - 1);
	(*map_ptr)->height = TILE_SIDE * (ft_lstsize(*head_ptr));
	(*map_ptr)->head_ptr = head_ptr;
	(*map_ptr)->moves = 0;
	//does lstsize give correct num?
	if (window_image(map_ptr) == NULL)
		return ;
	if (put_images_to_win(map_ptr, *((*map_ptr)->head_ptr), 0, 0) == NULL)
		return ; //are frees done before returning NULL?	
}

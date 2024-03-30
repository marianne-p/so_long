/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:43:42 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/30 13:31:13 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*window_image(t_win **map_ptr)
{
	(*map_ptr)->win_ptr = mlx_new_window((*map_ptr)->mlx_ptr,
			(*map_ptr)->width, (*map_ptr)->height, "so_long");
	if ((*map_ptr)->win_ptr == NULL)
	{
		mlx_destroy_display((*map_ptr)->mlx_ptr);
		free((*map_ptr)->mlx_ptr);
		return (NULL);
	}
	(*map_ptr)->wall_img_ptr = mlx_xpm_file_to_image((*map_ptr)->mlx_ptr,
			WALL_XPM_PATH, &((*map_ptr)->img_width), &((*map_ptr)->img_height));
	if ((*map_ptr)->wall_img_ptr == NULL)
	{
		mlx_destroy_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr);
		mlx_destroy_display((*map_ptr)->mlx_ptr);
		free((*map_ptr)->mlx_ptr);
		return (NULL);
	}
	return (*map_ptr);
}

void	ft_put_the_img(t_win **map_ptr, t_list *head, size_t i)
{
	const char	ch[5] = "1PCE0";

	if ((ft_strncmp((&((char *)head->content)[i]), &ch[0], 1)) == 0)
	{
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->wall_img_ptr, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
	}
	else if ((ft_strncmp((&((char *)head->content)[i]), &ch[1], 1)) == 0)
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->p_img->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
	else if ((ft_strncmp((&((char *)head->content)[i]), &ch[2], 1)) == 0)
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->flower_img->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
	else if (check_collectibles((*(*map_ptr)->head_ptr), 0, 0) == 0
		&& (ft_strncmp((&((char *)head->content)[i]), &ch[3], 1)) == 0)
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->exit_img->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
	else
		mlx_put_image_to_window((*map_ptr)->mlx_ptr, (*map_ptr)->win_ptr,
			(*map_ptr)->dimg->img, (*map_ptr)->width_now,
			(*map_ptr)->height_now);
}

void	*put_images_to_win(t_win **map_ptr, t_list *head)
{
	size_t		i;

	i = 0;
	(*map_ptr)->width_now = 0;
	(*map_ptr)->height_now = 0;
	while ((*map_ptr)->height_now < (*map_ptr)->height)
	{
		while ((*map_ptr)->width_now < (*map_ptr)->width
			&& i < ft_strlen((char *)head->content) - 1)
		{
			ft_put_the_img(map_ptr, head, i);
			i++;
			(*map_ptr)->width_now += TILE_SIDE;
		}
		i = 0;
		head = head->next;
		(*map_ptr)->width_now = 0;
		(*map_ptr)->height_now += TILE_SIDE;
	}
	return (map_ptr);
}

int	handle_keys(int keysum, void *param)
{
	if (keysum == XK_Escape)
	{
		close_win(param);
		exit (1);
	}
	if (keysum == XK_w || keysum == XK_Up)
		put_images_to_win((t_win **)&param,
			check_and_change(((t_win *)param), 4, NULL, NULL));
	if (keysum == XK_s || keysum == XK_Down)
		put_images_to_win((t_win **)&param,
			check_and_change(((t_win *)param), 3, NULL, NULL));
	if (keysum == XK_a || keysum == XK_Left)
		put_images_to_win((t_win **)&param,
			check_and_change(((t_win *)param), 2, NULL, NULL));
	if (keysum == XK_d || keysum == XK_Right)
		put_images_to_win((t_win **)&param,
			check_and_change(((t_win *)param), 1, NULL, NULL));
	print_the_moves((t_win *)param);
	return (0);
}

void	create_map_win(t_win **map_ptr, t_list **head_ptr)
{
	t_list	*head_cpy;
	t_list	*head;

	head = *head_ptr;
	head_cpy = ft_lstnew(ft_strdup((*head_ptr)->content));
	ft_printf("COPY STR\n");
	ft_printf("%s", (char *)head_cpy->content);
	(*map_ptr)->exit_cpy = head_cpy;
	while (head->next != NULL)
	{
		head = head->next;
		ft_lstadd_back(&head_cpy, ft_lstnew(ft_strdup(head->content)));
		ft_printf("%s", (char *)head->content);
	}
	head = *head_ptr;
	(*map_ptr)->width = TILE_SIDE
		* (ft_strlen((char *)(*head_ptr)->content) - 1);
	(*map_ptr)->height = TILE_SIDE * (ft_lstsize(*head_ptr));
	(*map_ptr)->head_ptr = head_ptr;
	(*map_ptr)->moves = 0;
	if (window_image(map_ptr) == NULL)
		return ;
	if (put_images_to_win(map_ptr, *((*map_ptr)->head_ptr)) == NULL)
		return ;
}

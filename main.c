/* ************************************************************************** */
/*	                                                                        */
/*	                                                    :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*	                                                +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>	                  +#+  +:+       +#+        */
/*	                                            +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:05:12 by mpihur	        #+#    #+#             */
/*   Updated: 2024/03/30 13:19:49 by mpihur           ###   ########.fr       */
/*	                                                                        */
/* ************************************************************************** */

#include "so_long.h"

int	handle_error(char *error, int ernum)
{
	perror(error);
	return (ernum);
}

void	create_the_map(t_list *head, char **map)
{
	map = (char **)malloc(ft_lstsize(head) * sizeof(char *));
	if (!map)
		exit(handle_error("Map alloc in create_the_map:", 1));
	while (head != NULL && head->content != NULL)
	{
		ft_printf("%s", head->content);
		head = head->next;
	}
	free(map);
}

static t_list	*init_game(char **argv, t_win **map, t_list *head)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(handle_error("Fd issue", 1));
	line = get_next_line(fd);
	head = ft_lstnew(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	(*map)->head_ptr = &head;
	create_square(*map);
	create_collectible(*map);
	if (verify_the_map(head, 0, *map) != 0)
		exit (handle_error_and_free("Map not verified", 1, *map));
	create_map_win(map, &head);
	return (head);
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_win	*map;

	map = (t_win *)malloc(sizeof(t_win));
	if (map == NULL)
		return (handle_error("Map alloc: ", 1));
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (handle_error("Mlx_ptr init: ", 1));
	if (argc != 2)
		exit(write(2, "Check args\n", 11));
	head = init_game(argv, &map, NULL);
	mlx_key_hook(map->win_ptr, &handle_keys, (void *)map);
	mlx_hook(map->win_ptr, DestroyNotify, ButtonReleaseMask,
		&close_win, (void *)map);
//	mlx_loop_hook(map->mlx_ptr, put_images_to_win_loop, (void *)map);
	mlx_loop(map->mlx_ptr);
	ft_lstclear(&head, free);
	free(map);
	return (0);
}

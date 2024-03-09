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
	//ft_printf("%d\n", i);
	while (head != NULL && head->content != NULL)
	{
		ft_printf("%s", head->content);
		head = head->next;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(handle_error("Fd issue", 1));
	line = get_next_line(fd);
	head = ft_lstnew(line);
	while ((line =  get_next_line(fd)) != NULL)
		ft_lstadd_back(&head, ft_lstnew(line));
	create_the_map(head, NULL);
	if (verify_the_map(head) != 0)
		return (1);
	create_map_win(&map, &head);
	mlx_key_hook(map->win_ptr, &handle_keys, (void *)map);
	mlx_hook(map->win_ptr, ON_DESTROY, 0L, &close_win, (void *)map);
	mlx_loop(map->mlx_ptr);
	ft_lstclear(&head, free);
	free(map);
	//ft_printf("%p\n", head);
	return (0);
}

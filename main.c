#include "so_long.h"

int	handle_error(char *error, int ernum)
{
	perror(error);
	return (ernum);
}

void	create_the_map(t_list *head, int i, char **map)
{
	map = (char **)malloc(ft_lstsize(head) * sizeof(char *));
	if (!map)
		exit(handle_error("Map alloc in create_the_map:", 1));
	ft_printf("%d\n", i);
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

	if (argc != 2)
		exit(write(2, "Check args\n", 11));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(handle_error("Fd issue", 1));
	line = get_next_line(fd);
	head = ft_lstnew(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	create_the_map(head, 0, NULL);
	ft_lstclear(&head, free);
	ft_printf("%p\n", head);
	return (0);
}

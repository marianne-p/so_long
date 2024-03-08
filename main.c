#include "so_long.h"
#include "libft/libft.h"

void	create_the_map(t_list *head)
{
	while (head != NULL)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}

int	handle_error(char *error)
{
	perror(error);
	return (1);
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
		exit(handle_error("Fd issue"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	create_the_map(head);
	return (0);
}

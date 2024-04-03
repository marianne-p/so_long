/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:17:15 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 17:22:45 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_list *head)
{
	size_t	len;

	len = ft_strlen(head->content);
	while (head->next != NULL && head->next->content != NULL)
	{
		if (len != ft_strlen(head->next->content))
			return (1);
		head = head->next;
	}
	return (0);
}

int	letter_count(t_list *head, char a, int count, int i)
{
	while (head != NULL && head->content != NULL)
	{
		while (((char *)head->content)[i])
		{
			if (((char *)head->content)[i] == a)
				count++;
			i++;
		}
		i = 0;
		head = head->next;
	}
	return (count);
}

int	contains_ecp(t_list *head)
{
	if (letter_count(head, 'E', 0, 0) != 1)
	{
		if (write(2, "Incorrect num of Exits\n", 23) < 0)
			exit(handle_error("Write() for E count in 'contains_ecp'", 1));
		return (1);
	}
	if (letter_count(head, 'C', 0, 0) < 1)
	{
		if (write(2, "No Collectibles on the Map\n", 27) < 0)
			exit (handle_error("Write() for C count in 'contains_ecp'", 1));
		return (1);
	}
	if (letter_count(head, 'P', 0, 0) != 1)
	{
		if (write(2, "Incorrect number of Players\n", 28) < 0)
			exit(handle_error
				("Write() for letter count in 'contains_ecp': ", 1));
		return (1);
	}
	return (0);
}

int	has_walls(t_list *head, int i, t_list *last, int len)
{
	while (i < len - 1 && ((char *)head->content)[i]
			&& ((char *)last->content)[i])
	{
		if ((ft_strncmp(&((const char *)head->content)[i], "1", 1) != 0)
		|| (ft_strncmp(&((char *)last->content)[i], "1", 1) != 0))
			return (1);
		i++;
	}
	while (head != last)
	{
		if (((char *)head->content)[0] != '1'
			|| ((char *)head->content)[ft_strlen(head->content) - 2] != '1')
			return (1);
		head = head->next;
	}
	return (0);
}

/*
1. Map is rectangular.
2. Contain 1 E, 1 C, 1 P.
3. Surrounded by walls.
4. Valid path to collectibles and exit.
*/
int	verify_the_map(t_list *head, int res, t_win *map)
{
	if (is_rectangular(head) != 0)
		exit(handle_error_and_free("Map not rectangular", 1, map));
	if (contains_ecp(head) != 0)
		exit(handle_error_and_free(" ", 1, map));
	if (has_walls(head, 0, ft_lstlast(head), ft_strlen(head->content)) != 0)
		exit(handle_error_and_free("No walls: ", 1, map));
	res = check_the_path(head, 0);
	if (res > 0)
		exit(handle_error_and_free("No path to C, E or P", 1, map));
	return (0);
}

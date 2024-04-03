/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:12:56 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 15:12:57 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void    print_the_head(t_list   *head)
{
    while (head != NULL)
    {
        ft_printf("%s\n", (char *)head->content);
        head = head->next;
    }
}*/

void	check_before_move(char tile, t_win *map)
{
	if (exit_or_noexit(&tile, map) == 0)
		exit (close_win(map));
	if (ft_strncmp("N", &tile, 1) == 0)
	{
		ft_printf("Oh no! You touched the ENEMY! \n");
		exit (close_win(map));
	}
}

void	find_and_put_exit(t_win *map, int i, t_list *head, int count)
{
	int		j;

	j = 0;
	while (head != NULL)
	{
		while (i < (int)ft_strlen((head)->content) - 1)
		{
			if (ft_strncmp(&((char *)(head)->content)[i], "E", 1) == 0)
			{
				head = *(map->head_ptr);
				while (j++ != count)
					head = head->next;
				((char *)head->content)[i] = 'E';
				return ;
			}
			i++;
		}
		count++;
		head = head->next;
		i = 0;
	}
}

int	exit_or_noexit(char *tile, t_win *map)
{
	if (check_collectibles(*(map->head_ptr), 0, 0) == 0)
		find_and_put_exit(map, 0, map->exit_cpy, 0);
	else
		return (-1);
	if (ft_strncmp(tile, "E", 1) != 0)
		return (-1);
	return (0);
}

int	check_collectibles(t_list *head, int i, int count)
{
	while (head != NULL)
	{
		while (i < (int)ft_strlen((char *)head->content) - 1)
		{
			if (ft_strncmp(&((char *)head->content)[i], "C", 1) == 0)
				count++;
			i++;
		}
		i = 0;
		head = head->next;
	}
	return (count);
}

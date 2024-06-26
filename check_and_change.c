/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:04:43 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 15:06:36 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*mv_up(t_win *map, t_list *temp, t_list *prev, int i)
{
	if (exit_or_noexit(&((char *)prev->content)[i], map) == 0)
		exit (close_win(map));
	((char *)prev->content)[i] = 'P';
	((char *)temp->content)[i] = '0';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	return (*(map->head_ptr));
}

t_list	*mv_down(t_win *map, t_list *temp, int i)
{
	if (exit_or_noexit(&((char *)temp->next->content)[i], map) == 0)
		exit (close_win(map));
	((char *)temp->content)[i] = '0';
	((char *)temp->next->content)[i] = 'P';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	return (*(map->head_ptr));
}

t_list	*mv_rl(t_win *map, t_list *temp, int i, int j)
{
	if (exit_or_noexit(&((char *)temp->content)[j], map) == 0)
		exit (close_win(map));
	((char *)temp->content)[i] = '0';
	((char *)temp->content)[j] = 'P';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	return (*(map->head_ptr));
}

void	print_the_moves(t_win *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 12, 0xFFFF00, "count =");
	map->str = ft_itoa(map->moves);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 80, 12, 0xFFFF00, map->str);	
	free(map->str);
}

t_list	*check_and_change(t_win *map, int v, t_list *temp, t_list *prev)
{
	int	i;

	temp = (*(map->head_ptr));
	i = find_player(&temp, 0, 'P');
	if (i < 0)
		return (NULL);
	if (v == 4)
		prev = find_prev_node(temp, *(map->head_ptr));
	if (v == 4 && ft_strncmp(&((char *)prev->content)[i], "1", 1) != 0)
		return (mv_up(map, temp, prev, i));
	if (v == 3 && ft_strncmp(&((char *)temp->next->content)[i], "1", 1) != 0)
		return (mv_down(map, temp, i));
	if (v == 2 && ft_strncmp(&((char *)temp->content)[i - 1], "1", 1) != 0)
		return (mv_rl(map, temp, i, i - 1));
	if (v == 1 && ft_strncmp(&((char *)temp->content)[i + 1], "1", 1) != 0)
		return (mv_rl(map, temp, i, i + 1));
	print_the_moves(map);
	return (*(map->head_ptr));
}

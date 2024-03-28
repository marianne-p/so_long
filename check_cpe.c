/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cpe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:59:12 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 16:00:32 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cpe(t_list **head, const char *list, int i, int j)
{
	t_list	*temp;

	temp = *head;
	while (i < 3)
	{
		while (((char *)temp->content)[j])
		{
			if (ft_strncmp(&list[i], &((char *)temp->content)[j], 1) == 0)
				exit (handle_error("No path to Exit or Collectible", 1));
			j++;
		}
		i++;
		temp = *head;
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cpe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:59:12 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 17:22:53 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cpe(t_list **head, int i, int j)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = *head;
	while (temp)
	{
		while (((char *)temp->content)[j + 1])
		{
			if (ft_strncmp("V", &((char *)temp->content)[j], 1) != 0
				&& ft_strncmp("1", &((char *)temp->content)[j], 1) != 0)
				count++;
			j++;
		}
		i++;
		j = 0;
		temp = temp->next;
	}
	return (count);
}
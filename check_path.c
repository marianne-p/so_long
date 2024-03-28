/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:59:27 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/28 15:59:28 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*find_prev_node(t_list *temp, t_list *head)
{
	while (head != NULL)
	{
		if (head->next == temp)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	find_player(t_list **temp, int i, char s)
{
	while (*temp != NULL)
	{
		while (i < (int)ft_strlen((*temp)->content) - 1)
		{
			if (ft_strncmp(&((char *)(*temp)->content)[i], &s, 1) == 0)
				return (i);
			i++;
		}
		*temp = (*temp)->next;
		i = 0;
	}
	return (i);
}

static void	help_verify(t_list **temp, t_list **head, int i, t_list *prev)
{
	if ((*temp)->next != NULL
		&& ft_strncmp(&((char *)(*temp)->next->content)[i], "1", 1) != 0
		&& ft_strncmp(&((char *)(*temp)->next->content)[i], "V", 1) != 0)
	{
		((char *)(*temp)->next->content)[i] = 'V';
		verify_head_path(&((*temp)->next), head, i, NULL);
	}
	if (prev != NULL && ft_strncmp(&((char *)(prev->content))[i], "1", 1) != 0
		&& ft_strncmp(&((char *)prev->content)[i], "V", 1) != 0)
	{
		((char *)(prev->content))[i] = 'V';
		verify_head_path(&prev, head, i, NULL);
	}
}

void	verify_head_path(t_list **temp, t_list **head, int i, t_list *prev)
{
	if (i == -1 || (*temp) == NULL)
		return ;
	prev = find_prev_node(*temp, *head);
	if (i > 0 && (((char *)(*temp)->content)[i - 1])
		&& ft_strncmp(&((char *)(*temp)->content)[i - 1], "1", 1) != 0
		&& ft_strncmp(&((char *)(*temp)->content)[i - 1], "V", 1) != 0)
	{
		((char *)((*temp)->content))[i - 1] = 'V';
		verify_head_path(temp, head, i - 1, NULL);
	}
	if (i + 1 < ((int)ft_strlen((char *)(*temp)->content) - 1)
		&& ft_strncmp(&((char *)(*temp)->content)[i + 1], "1", 1) != 0
		&& ft_strncmp(&((char *)(*temp)->content)[i + 1], "V", 1) != 0)
	{
		((char *)(*temp)->content)[i + 1] = 'V';
		verify_head_path(temp, head, i + 1, NULL);
	}
	help_verify(temp, head, i, prev);
	return ;
}

int	check_the_path(t_list *head)
{
	t_list	*temp;
	t_list	*head_cpy;

	head_cpy = ft_lstnew(ft_strdup(head->content));
	while (head->next != NULL)
	{
		head = head->next;
		ft_lstadd_back(&head_cpy, ft_lstnew(ft_strdup(head->content)));
	}
	temp = head_cpy;
	verify_head_path(&temp, &head_cpy, find_player(&temp, 0, 'P'), NULL);
	temp = head_cpy;
	check_cpe(&temp, "CPE", 0, 0);
	ft_lstclear(&temp, free);
	return (0);
}

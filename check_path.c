#include "so_long.h"

t_list  *find_prev_node(t_list  *temp, t_list *head)
{
    while (head != NULL)
    {
        if (head->next == temp)
            return (head);
        head = head->next;
    }
    return (NULL);
}

int     find_player(t_list  **temp, int i)
{
    while (*temp != NULL)
    {
        while (i < (int)ft_strlen((*temp)->content) - 1)
        {
            if (ft_strncmp(&((char *)(*temp)->content)[i], "P", 1) == 0)
                return (i);
            i++;
        }
        *temp = (*temp)->next;
    }
    return (-1);
}

void    verify_head_path(t_list **temp, t_list **head, int i, t_list *prev)
{
    if (i == -1 || (*temp) == NULL)
        return ;
    /*moving left*/
    if (i - 1 >= 0 && ft_strncmp(&((char *)(*temp)->content)[i - 1], "1", 1) != 0)
    {
        ((char *)(*temp)->content)[i - 1] = 'V';
        verify_head_path(temp, head, i - 1, find_prev_node(*temp, *head));
    }
    /*moving right*/
    if (i + 1 < ((int)ft_strlen((char *)(*temp)->content) - 1) && ft_strncmp(&((char *)(*temp)->content)[i + 1], "1", 1) != 0)
    {
        ((char *)(*temp)->content)[i + 1] = 'V';
        verify_head_path(temp, head, i + 1, find_prev_node(*temp, *head));
    }
    /*moving down*/
    if ((*temp)->next != NULL && ft_strncmp(&((char *)(*temp)->next->content)[i], "1", 1) != 0)
    {
        ((char *)(*temp)->next->content)[i] = 'V';
        verify_head_path(&((*temp)->next), head, i, find_prev_node(*temp, *head));
    }
    /*moving up*/
    if (prev != NULL && ft_strncmp(&((char *)(prev->content))[i], "1", 1) != 0)
    {
        ((char *)(prev->content))[i] = 'V';
        verify_head_path(&prev, head, i, find_prev_node(prev, *head));
    }
}

int     check_the_path(t_list *head)
{
    t_list  *temp;
    t_list  *head_cpy;

    head_cpy = ft_lstnew(ft_strdup(head->content));
    while (head->content != NULL)
    {
        head = head->next;
        ft_lstadd_back(&head_cpy, ft_lstnew(ft_strdup(head->content)));
    }
    temp = head_cpy;
    verify_head_path(&temp, &head_cpy, find_player(&temp, 0), find_prev_node(temp, head_cpy));
    while (head != NULL)
    {
        ft_printf("%d\n", head->content);
        head = head->next;
    }
    /*CHANGE!!*/
    return (1);
}
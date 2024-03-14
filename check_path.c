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

int     find_player(t_list  **temp)
{

}

void    verify_head_path(t_list **temp, t_list **head, int i, t_list *prev)
{
    /*moving left*/
    if (i - 1 >= 0 && ft_strncmp(((int *)(*temp)->content)[i - 1], "1", 1) != 0)
    {
        ((int *)(*temp)->content)[i - 1] = "V";
        verify_head_path(temp, head, i - 1, find_prev_node(*temp, *head));
    }
    /*moving right*/
    if (i + 1 < (ft_strlen((char *)(*temp)->content) - 1) && ft_strncmp(((int *)(*temp)->content)[i + 1], "1", 1) != 0)
    {
        ((int *)(*temp)->content)[i + 1] = "V";
        verify_head_path(temp, head, i + 1, find_prev_node(*temp, *head));
    }
    /*moving down*/
    if ((*temp)->next != NULL && ft_strncmp(((int *)(*temp)->next->content)[i], "1", 1) != 0)
    {
        ((int *)(*temp)->next->content)[i] = "V";
        verify_head_path(&((*temp)->next), head, i, find_prev_node(*temp, *head));
    }
    /*moving up*/
    if (prev != NULL && ft_strncmp(((int *)(prev->content))[i], "1", 1) != 0)
    {
        ((int *)(prev->content))[i] = "V";
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
    verify_head_path(&temp, &head_cpy, find_player(&temp), find_prev_node(temp, head_cpy));
}
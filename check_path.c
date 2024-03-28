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

int     find_player(t_list  **temp, int i, char s)
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

void    verify_head_path(t_list **temp, t_list **head, int i, t_list *prev)
{
    if (i == -1 || (*temp) == NULL)
        return ;
    /*moving left*/
    prev = find_prev_node(*temp, *head);
    if (i > 0 && (((char *)(*temp)->content)[i - 1]) && ft_strncmp(&((char *)(*temp)->content)[i - 1], "1", 1) != 0 && ft_strncmp(&((char *)(*temp)->content)[i - 1], "V", 1) != 0)
    {
        ((char *)((*temp)->content))[i - 1] = 'V';
        verify_head_path(temp, head, i - 1, NULL);
    }
    /*moving right*/
    if (i + 1 < ((int)ft_strlen((char *)(*temp)->content) - 1) && ft_strncmp(&((char *)(*temp)->content)[i + 1], "1", 1) != 0 && ft_strncmp(&((char *)(*temp)->content)[i + 1], "V", 1) != 0)
    {
        ((char *)(*temp)->content)[i + 1] = 'V';
        verify_head_path(temp, head, i + 1, NULL);
    }
    /*moving down*/
    if ((*temp)->next != NULL && ft_strncmp(&((char *)(*temp)->next->content)[i], "1", 1) != 0 && ft_strncmp(&((char *)(*temp)->next->content)[i], "V", 1) != 0)
    {
        ((char *)(*temp)->next->content)[i] = 'V';
        verify_head_path(&((*temp)->next), head, i, NULL);
    }
    /*moving up*/
    if (prev != NULL && ft_strncmp(&((char *)(prev->content))[i], "1", 1) != 0 && ft_strncmp(&((char *)prev->content)[i], "V", 1) != 0)
    {
        ((char *)(prev->content))[i] = 'V';
        verify_head_path(&prev, head, i, NULL);
    }
    return ;
}

int     check_cpe(t_list **head, const char *list, int i, int j)
{
    t_list  *temp;

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

int     check_the_path(t_list *head)
{
    t_list  *temp;
    t_list  *head_cpy;

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
    /*while (head_cpy != NULL)
    {
        ft_printf("%s", head_cpy->content);
        head_cpy = head_cpy->next;
    }*/
    /*CHANGE!!*/
    ft_lstclear(&temp, free);
    return (0);
}

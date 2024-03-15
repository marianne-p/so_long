#include "so_long.h"

int check_collectibles(t_list *head, int i, int count)
{
    while (head != NULL)
    {
        while (i < (int)ft_strlen((char *)head->content) - 1)
        {
            if (ft_strncmp(&((char *)head->content)[i], "C", 1) == 0)
                count++;
            i++;
        }
        head = head->next;
    }
    return (count);
}
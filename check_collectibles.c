#include "so_long.h"

static char    *find_pointer_to_exit(t_list *head, int i)
{
    while (head != NULL)
    {
        while (i < (int)ft_strlen((head)->content) - 1)
        {
            if (ft_strncmp(&((char *)(head)->content)[i], "E", 1) == 0)
                return ((((char *)head->content) + (i * sizeof((char *)head->content)[i])));
            //ft_printf("i=%d, ", i);
            i++;
        }
        head = head->next;
        i = 0;
    }
    return (NULL);
}

int exit_or_noexit(char *tile, t_win *map)
{
    //check if tile is the same as the exit location
    if (tile != find_pointer_to_exit(map->exit_cpy, 0))
        return (-1);
    if (check_collectibles(*(map->head_ptr), 0, 0) != 0)
        return (-1);
    return (0); 
}

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
#include "so_long.h"

/*void    print_the_head(t_list   *head)
{
    while (head != NULL)
    {
        ft_printf("%s\n", (char *)head->content);
        head = head->next;
    }
}*/

void    find_and_put_exit(t_win *map, int i, t_list *head, int count)
{
    int j;

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

/*static char    *find_pointer_to_exit(t_list *head, int i)
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
*/
int exit_or_noexit(char *tile, t_win *map)
{
    //check if tile is the same as the exit location
    if (check_collectibles(*(map->head_ptr), 0, 0) == 0)
        find_and_put_exit(map, 0, map->exit_cpy, 0);
    else
        return (-1);
    if (ft_strncmp(tile, "E", 1) != 0)
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
        i = 0;
        head = head->next;
    }
    return (count);
}
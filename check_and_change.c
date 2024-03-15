#include "so_long.h"

t_list  *check_and_change(t_win *map, int v, t_list *temp, t_list *prev)
{
    int     i;

    temp = *(map->head_ptr);
    i = find_player(&temp, 0);
    ft_printf("%d\n", i);
    if (i < 0)
        return (NULL);
    prev = find_prev_node(temp, *(map->head_ptr));
    if (v == 4)
    {
        //if Exit, check whether all Collected
        ((char *)temp->content)[i] = '0';
        ((char *)prev->content)[i] = 'P';
        map->moves++;
        ft_printf("Moves: %d\n", map->moves);
        return (*(map->head_ptr));
    }
    return (*(map->head_ptr));
}
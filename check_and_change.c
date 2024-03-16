#include "so_long.h"

t_list  *mv_up(t_win *map, t_list *temp, t_list *prev, int i)
{
    //ft_printf("Move up\n");
    if (exit_or_noexit(&((char *)prev->content)[i], map) == 0)
        exit (close_win(map));
    //if Exit, check whether all Collected
    ((char *)prev->content)[i] = 'P';
    ((char *)temp->content)[i] = '0';
    map->moves++;
    ft_printf("Moves: %d\n", map->moves);
    return (*(map->head_ptr));
}

t_list  *mv_down(t_win *map, t_list *temp, int i)
{
    //ft_printf("Move down\n");
    if (exit_or_noexit(&((char *)temp->next->content)[i], map) == 0)
        exit (close_win(map));
    //Exit triger check
    ((char *)temp->content)[i] = '0';
    ((char *)temp->next->content)[i] = 'P';
    map->moves++;
    ft_printf("Moves: %d\n", map->moves);
    return (*(map->head_ptr));
}

t_list  *mv_rl(t_win *map, t_list *temp, int i, int j)
{
    //ft_printf("Move r/left\n");
    //Exit triger check
    if (exit_or_noexit(&((char *)temp->content)[j], map) == 0)
        exit (close_win(map));
    ((char *)temp->content)[i] = '0';
    ((char *)temp->content)[j] = 'P';
    map->moves++;
    ft_printf("Moves: %d\n", map->moves);
    return (*(map->head_ptr));
}

t_list  *check_and_change(t_win *map, int v, t_list *temp, t_list *prev)
{
    int     i;

    temp = (*(map->head_ptr));
    //ft_printf("%s\n", temp->content);
    i = find_player(&temp, 0, 'P');
    //ft_printf("%s\n", temp->content);
    //ft_printf("%d\n", i);
    if (i < 0)
        return (NULL);
    if (v == 4)
        prev = find_prev_node(temp, *(map->head_ptr));
    if (v == 4 && ft_strncmp(&((char *)prev->content)[i], "1", 1) != 0)
        return (mv_up(map, temp, prev, i));
    if (v == 3 && ft_strncmp(&((char *)temp->next->content)[i], "1", 1) != 0)
        return (mv_down(map, temp, i));
    if (v == 2  && ft_strncmp(&((char *)temp->content)[i - 1], "1", 1) != 0)
        return (mv_rl(map, temp, i, i -1));
    if (v == 1 && ft_strncmp(&((char *)temp->content)[i + 1], "1", 1) != 0)
        return (mv_rl(map, temp, i, i + 1)); 
    return (*(map->head_ptr));
}
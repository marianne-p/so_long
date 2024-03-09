#include "so_long.h"

t_win	*create_map_win(t_list *head)
{
	t_win	*map;

	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (NULL);
	map->width = TILE_SIDE * (ft_strlen((char *)head->content) - 1);
	map->height = TILE_SIDE * (ft_lstsize(head));
	//does lstsize give correct num?
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->width, map->height, "so_long");
	if (map->win_ptr == NULL)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
		return (NULL);
		// is other stuff free after receiving NULL in main?
	}
	map->wall_img_ptr = mlx_xpm_file_to_img(map->mlx_ptr, WALL_XPM_PATH,
		&(map->img_width), &(map->img_height))
}

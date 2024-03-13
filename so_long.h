/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:33:14 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/13 16:50:21 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define TILE_SIDE 64
# define WALL_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/1.xpm"
# define PLAYER_PATH "/home/mpihur/42CORE/so_long/xpm/char.xpm"
# define FLOWER_PATH "/home/mpihur/42CORE/so_long/xpm/flow.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct s_win
{
    void    *mlx_ptr;
    t_list  **head_ptr;
    void    *win_ptr;
    void    *wall_img_ptr;
	t_data	*dimg;
	t_data	*p_img;
	t_data	*flower_img;
    int     width;
    int     height;
    int     img_width;
    int     img_height;
} t_win;

int	handle_error(char *error, int ernum);
int verify_the_map(t_list *head);
void    create_square(t_win *map);
void create_map_win(t_win **map_ptr, t_list **head_ptr);
int	close_win(void *param);
int	handle_keys(int keysum, void *param);
void    create_collectible(t_win *map);

#endif

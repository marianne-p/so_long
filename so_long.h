/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:33:14 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/10 19:13:41 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define TILE_SIDE 64
# define WALL_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/tile027.xpm"
# define ZERO_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/tile003.xpm"

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

typedef struct s_win
{
    void    *mlx_ptr;
    t_list  **head_ptr;
    void    *win_ptr;
    void    *wall_img_ptr;
    int     width;
    int     height;
    int     img_width;
    int     img_height;
} t_win;

int	handle_error(char *error, int ernum);
int verify_the_map(t_list *head);
void create_map_win(t_win **map_ptr, t_list **head_ptr);
int	close_win(void *param);
int	handle_keys(int keysum, void *param);

#endif

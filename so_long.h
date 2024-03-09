/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:33:14 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/08 16:40:23 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define TILE_SIDE 16
# define WALL_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/tile001.xpm"
# define ZERO_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/tile003.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *wall_img_ptr;
    int     width;
    int     height;
    int     img_width;
    int     img_height;
} t_win;

int	handle_error(char *error, int ernum);
int verify_the_map(t_list *head);

#endif

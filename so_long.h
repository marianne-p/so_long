/* ************************************************************************** */
/*	                                                                        */
/*	                                                    :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*	                                                +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>	                  +#+  +:+       +#+        */
/*	                                            +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:33:14 by mpihur	        #+#    #+#             */
/*   Updated: 2024/03/30 13:28:58 by mpihur           ###   ########.fr       */
/*	                                                                        */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIDE 64
# define WALL_XPM_PATH "/home/mpihur/42CORE/so_long/xpm/1.xpm"
# define PLAYER_PATH "/home/mpihur/42CORE/so_long/xpm/char.xpm"
# define FLOWER_PATH "/home/mpihur/42CORE/so_long/xpm/flow.xpm"
# define EXIT_PATH "/home/mpihur/42CORE/so_long/xpm/exit.xpm"
# define ENEMY_1 "/home/mpihur/42CORE/so_long/xpm/2.xpm"
# define ENEMY_2 "/home/mpihur/42CORE/so_long/xpm/3.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_win
{
	void	*mlx_ptr;
	t_list	**head_ptr;
	void	*win_ptr;
	void	*wall_img_ptr;
	t_data	*dimg;
	t_data	*p_img;
	t_data	*flower_img;
	t_data	*exit_img;
	t_data	*enemy_fst;
	t_data	*enemy_snd;
	int		frm;
	int		width;
	int		height;
	int		width_now;
	int		height_now;
	int		img_width;
	int		img_height;
	int		moves;
	char	*str;
	t_list	*exit_cpy;
}	t_win;

int		handle_error(char *error, int ernum);
int		verify_the_map(t_list *head, int res, t_win *map);
int		handle_error_and_free(char *error, int ernum, t_win *map);
void	verify_head_path(t_list **temp, t_list **head, int i, t_list *prev);
int		check_the_path(t_list *head, int ret);
int		check_cpe(t_list **head, int i, int j);
/**/
void	create_square(t_win *map);
void	create_collectible(t_win *map);
/**/
void	create_map_win(t_win **map_ptr, t_list **head_ptr);
t_list	*check_and_change(t_win *map, int v, t_list *temp, t_list *prev);
void	print_the_moves(t_win *map);
void	check_before_move(char tile, t_win *map);
int		exit_or_noexit(char *tile, t_win *map);
int		check_collectibles(t_list *head, int i, int count);
void	*put_images_to_win(t_win **map_ptr, t_list *head);
int		put_more_img(t_win **map_ptr, t_list *head, size_t i);
void    update_enemy(t_win **map_ptr);
int		close_win(void *param);
/**/
int		handle_keys(int keysum, void *param);
int		find_player(t_list **temp, int i, char s);
t_list	*find_prev_node(t_list *temp, t_list *head);

#endif
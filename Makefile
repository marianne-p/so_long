# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpihur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:00:28 by mpihur            #+#    #+#              #
#    Updated: 2024/03/30 13:24:05 by mpihur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CC	:= gcc
GNL	:= get_next_line/
SRCS	:= main.c verify_the_map.c check_path.c check_cpe.c close_and_free.c \
	   create_map_win.c create_square.c create_cpe_img.c check_and_change.c check_collectibles.c \
	   $(GNL)get_next_line.c $(GNL)get_next_line_utils.c	   
OBJ := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror -g
FT_PRINTF := ./ft_printf/libftprintf.a
LIBFT := ./libft/libft.a
LDFLAGS := -I. -L./libft -lft -L./ft_printf -lftprintf
MLXFLAGS := -Lminilibx-linux -lmlx -Iminilibx-linux -lXext -lX11 -lm -lz 

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ) 
		$(CC) $(OBJ) $(LDFLAGS) -I$(GNL) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	make bonus -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	rm -rf $(OBJ)
	make -C ./ft_printf clean
	make -C ./libft clean

fclean:	clean
	rm $(NAME)
	make -C ./ft_printf fclean
	make -C ./libft fclean

all:	$(LIBFT) $(FT_PRINTF) $(OBJ) $(NAME)

re:	fclean all

.PHONY: clean fclean

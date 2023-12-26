NAME	:= so_long
CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror
OBJ	:= main.c


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

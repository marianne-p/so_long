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

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int	handle_error(char *error, int ernum);
int verify_the_map(t_list *head);

#endif

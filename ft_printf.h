/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:06:19 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/08 16:47:25 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_checker(char c, va_list ap, int ret);
int				ft_printf(const char *str, ...);
/*pointer and hex */
int				ft_ptr(uintptr_t ptr, int ret);
int				ft_to_hex_up(unsigned long int num, int ret);
int				ft_to_hex(unsigned long int num, int ret);
/*working with str*/
unsigned int	ft_strlen_pf(char *str, unsigned int count);
int				ft_putchar(int a, int ret);
int				ft_putstr(char *str, int ret);
/*numbers*/
int				ft_putnbr(long int nbr, int ret);

#endif

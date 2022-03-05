/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:50:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 13:37:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
#include <stdio.h>

/* flag corresponding to a prime number
- : 2
0 : 3
  : 5
# : 7
+ : 11
*/

typedef struct s_spec
{
	int	flag;
	int	width;
	int	precis;
}	t_spec;

int	ft_printf(const char *s, ...);

/* print */
int		print_factory(const char *s, int *i, va_list arg_n);

/* get */
int		get_flag(const char *s, int *i);
int		get_width(const char *s, int *i, char **flag);
int		get_precis(const char *s, int *i);
int		*get_instruction(int n, ...);

/* width */
int	width_nbr(int len, t_spec spec);
int	width_hex(int len, t_spec spec, int upper);
int	print_width(int width, int len, char c);

/* utils */
int		ft_putchar(int c);
int		ft_putstr(char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <min-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:21:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 18:36:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long long int n);
int	ft_puthex(unsigned int n, int upper);
int	ft_putptr(unsigned long long n, int on);
int	ft_nbrlen(long long int n, int base);
int	print(char type, va_list arg_n);
int	ft_printf(const char *s, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:10:56 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(const char *s, int *i, va_list arg_n)
{
	char	type;

	if (!s[*i])
		return (0);
	type = s[(*i)++];
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg_n, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(arg_n, unsigned int)));
	else if (type == 'x')
		return (ft_puthex(va_arg(arg_n, unsigned int), 0));
	else if (type == 'X')
		return (ft_puthex(va_arg(arg_n, unsigned int), 1));
	else if (type == 'c')
		return (ft_putchar(va_arg(arg_n, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg_n, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(arg_n, unsigned long long), 1));
	else
		return (ft_putchar(type));
}

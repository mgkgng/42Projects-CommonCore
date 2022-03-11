/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <min-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:10:56 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 18:35:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(char type, va_list arg_n)
{
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
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

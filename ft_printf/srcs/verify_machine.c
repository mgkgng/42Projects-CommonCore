/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_machine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:10:56 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/16 12:29:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_factory(int i, const char *s, va_list arg_n)
{
	int	result;

	result = 0;
	if (s[i] == 'd' || s[i] == 'i')
		result = ft_putnbr(va_arg(arg_n, int));
	else if (s[i] == 'u')
		result = ft_putnbr(va_arg(arg_n, unsigned int));
	else if (s[i] == 'x')
		result = ft_putnbr_base((unsigned int) va_arg(arg_n, int), \
				"0123456789abcdef", s[i]);
	else if (s[i] == 'X')
		result = ft_putnbr_base((unsigned int) va_arg(arg_n, int), \
				"0123456789ABCDEF", s[i]);
	else if (s[i] == 'c')
		result = ft_putchar(va_arg(arg_n, int));
	else if (s[i] == 's')
		result = ft_putstr(va_arg(arg_n, char *));
	else if (s[i] == 'p')
		result = ft_putnbr_base((unsigned long int) va_arg(arg_n, void *), \
				"0123456789abcdef", s[i]) + 2;
	else if (s[i] == '%')
		result = ft_putchar('%');
	return (result);
}

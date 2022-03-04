/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:19:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 18:16:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_width(int width, int len)
{
	int	i;

	if (len >= width)
		return (0);
	i = 0;
	while (i++ < width - len)
		ft_putchar(' ');
	return (i);
}

int	do_print(char type, va_list arg_n, t_spec spec)
{
	if (type == 'd' || type == 'i')
		return (print_d(va_arg(arg_n, int), spec));
	else if (type == 'u')
		return (print_u(va_arg(arg_n, unsigned int), spec));
	else if (type == 'x')
		return (print_x(va_arg(arg_n, unsigned int), spec, 0));
	else if (type == 'X')
		return (print_x(va_arg(arg_n, unsigned int), spec, 1));
	else if (type == 'c')
		return (print_c(va_arg(arg_n, int), spec));
	else if (type == 's')
		return (print_s(va_arg(arg_n, char *), spec));
	else if (type == 'p')
		return (print_p(va_arg(arg_n, unsigned long long), spec));
	else if (type == '%')
		return (print_c('%', spec));
	else
		return (0);
}

int	print_factory(const char *s, int *i, va_list arg_n)
{
	t_spec	spec;

	spec.flag = get_flag(s, i);
	spec.width = get_width(s, i, &spec.flag);
	spec.precis = get_precis(s, i);
	return (do_print(s[*i], arg_n, spec));
}
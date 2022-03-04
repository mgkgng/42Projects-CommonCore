/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:19:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 12:34:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_width(int width, int len)
{
	int	i;

	if (len >= width)
		return (0);
	i = 0;
	while (len + i++ < width)
		ft_putchar(' ');
	return (i);
}

int	print_c(int c, t_opt opt)
{
	int	len;
	
	len = 0;
	if (ft_strchr(opt.flag, '-')) {}
		// something here len += print_minus();
	else if (opt.width)
		len += print_width(opt.width, 1);
	ft_putchar(c);
	if (!c)
		ft_putchar(0);
	return (++len);
}

int	print_s(char *s, t_opt opt)
{
	
}

int	do_print2(char type, va_list arg_n, t_opt opt)
{
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(arg_n, int)));
	else if (type == 'u')
		return (ft_itoa(va_arg(arg_n, unsigned int)));
	else if (type == 'x')
		return (hex((unsigned int) va_arg(arg_n, int), 0));
	else if (type == 'X')
		return (hex((unsigned int) va_arg(arg_n, int), 1));
	else if (type == 'c')
		return (print_c(va_arg(arg_n, int), opt));
	else if (type == 's')
		return (print_s(va_arg(arg_n, char *), opt));
	else if (type == 'p')
		return (get_pointer((unsigned long int) va_arg(arg_n, void *)));
	else if (type == '%')
		return (to_string('%'));
	else
		return (NULL);
}

int	print_factory2(const char *s, int *i, va_list arg_n)
{
	t_opt	opt;
	t_print	print;

	opt.flag = get_flag(s, i);
	opt.width = get_width(s, i, &opt.flag);
	opt.precis = get_precis(s, i);
	return (do_print2(s[*i], arg_n, opt));
}
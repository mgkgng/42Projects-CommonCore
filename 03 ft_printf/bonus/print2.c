/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:19:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 13:11:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printstr(char *s, int precis)
{
	int	i;
	
	if (precis == -1)
		precis = ft_strlen(s);
	i = 0;
	while (s[i] && i < precis)
		ft_putchar(s[i++]);
	return (i);
}

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

int	print_x(unsigned int n, t_opt opt, int flag)
{
	int	len;
	int	hyphen;
// precision, width
//flag = '0', '#', '-'


}

int	print_c(int c, t_opt opt)
{
	int	len;
	int	hyphen;
	
	len = 0;
	hyphen = 0;
	if (ft_strchr(opt.flag, '-'))
		hyphen = 1;
	if (opt.width)
	{
		if (hyphen)
			ft_putchar(c);
		len += print_width(opt.width, 1);
		if (!hyphen)
			ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (++len);
}

int	print_s(char *s, t_opt opt)
{
	int	len;
	int	hyphen;
	char	*null_str;

	len = 0;
	hyphen = 0;
	null_str = ft_strdup("(null)");
	if (!s)
		s = null_str;
	if (ft_strchr(opt.flag, '-'))
		hyphen = 1;
	if (opt.width)
	{
		if (hyphen)
			len += ft_printstr(s, opt.precis);
		len += print_width(opt.width, ft_strlen(s) - opt.precis);
		if (!hyphen)
			len += ft_printstr(s, opt.precis);
	}
	else
		len += ft_printstr(s, opt.precis);
	free(null_str);
	return (len);
}

int	do_print2(char type, va_list arg_n, t_opt opt)
{
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(arg_n, int)));
	else if (type == 'u')
		return (ft_itoa(va_arg(arg_n, unsigned int)));
	else if (type == 'x')
		return (print_x(va_arg(arg_n, unsigned int), opt, 0));
	else if (type == 'X')
		return (print_x(va_arg(arg_n, unsigned int), opt, 1));
	else if (type == 'c')
		return (print_c(va_arg(arg_n, int), opt));
	else if (type == 's')
		return (print_s(va_arg(arg_n, char *), opt));
	else if (type == 'p')
		return (get_pointer((unsigned long int) va_arg(arg_n, void *)));
	else if (type == '%')
		return (to_string('%'));
	else
		return (0);
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
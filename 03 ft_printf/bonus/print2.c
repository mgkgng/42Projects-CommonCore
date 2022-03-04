/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:19:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 15:27:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pow(int nb, int pow)
{
	if (!pow)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

int	ft_printhex(unsigned int n, int precis, int flag)
{
	int				i;
	char			*set;
	unsigned int	tmp;
	int				len;	

	if (!flag)
		set = ft_strdup("0123456789abcdef");
	else
		set = ft_strdup("0123456789ABCDEF");
	len = 1;
	tmp = n;
	while (tmp > 15)
	{
		tmp /= 16;
		len++;
	}
	i = len;
	while (len++ < precis)
		ft_putchar('0');
	while (--i)
	{
		ft_putchar(set[n / 16 * ft_pow(16, i)]);
		n %= ft_pow(16, i);
	}
	return (len);
}

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

int	print_hashtag(int flag)
{
	if (!flag)
		ft_putstr("0x");
	else
		ft_putstr("0X");
	return (2);
}
int	print_x(unsigned int n, t_opt opt, int flag)
{
	int	len;
	int	hyphen;
	int	hashtag;

	len = 0;
	hyphen = 0;
	hashtag = 0;
	if (ft_strchr(opt.flag, '-'))
		hyphen = 1;

	if (opt.width)
	{
		if (hyphen) {}
		
	}
	else
	{
		
	}
// precision, width
//flag = '0', '#', '-'


}

int	print_c(int c, t_opt opt)
{
	int	len;
	
	len = 0;
	if (opt.width)
	{
		if (ft_strchr(opt.flag, '-'))
			ft_putchar(c);
		len += print_width(opt.width, 1);
		if (!ft_strchr(opt.flag, '-'))
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

	// flag ' '
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

int	print_p(void *n, t_opt opt)
{
	int	len;

	len = ft_putstr("0x");
	// should be unsigned long int
	len += ft_printhex((unsigned long int) n, opt.precis, 0);
	return (len);
}

int	ft_nbrlen(long long int n, int base)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > base - 1)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	ft_printnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_printnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (ft_nbrlen(n, 10));
}

int print_d(int n, t_opt opt)
{
	// precision, width
	// flag: '+', '0', ' ', '-'
}

int	print_u(unsigned int n, t_opt opt)
{
	// precision, width
	// flag: '+', '0', '-'
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
		return (print_p(va_arg(arg_n, void *), opt));
	else if (type == '%')
		return (print_c('%', opt));
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
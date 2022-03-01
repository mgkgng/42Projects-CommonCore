/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_machine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 19:52:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_len	print_factory(const char *s, int i, va_list arg_n)
{
	t_opt	opt;
	t_arg	*arg;
	t_len	res;

	opt.flag = ft_flag(s, &i);
	opt.width = ft_width_min(s, &i);
	opt.precis = ft_precision(s, &i);
	
	arg = ft_conversion(s[i], &res, arg_n);
	res.length = print_and_return(arg->data, arg->type, opt);
	res.index = i + 1;
	free(arg);
	return (res);
}

t_arg	*ft_conversion(char convert, t_len *result, va_list arg_n)
{
	t_arg	*arg;
	
	if (convert == 'd' || convert == 'i')
		arg->data = ft_itoa(va_arg(arg_n, int));
	else if (convert == 'u')
		arg->data = ft_itoa(va_arg(arg_n, unsigned int));
	else if (convert == 'x')
		arg->data = ft_itoa_base((unsigned int) va_arg(arg_n, int), \
			"0123456789abcdef");
	else if (convert == 'X')
		arg->data = ft_itoa_base((unsigned int) va_arg(arg_n, int), \
			"0123456789ABCDEF");
	else if (convert == 'c')
		arg->data = char_to_string(va_arg(arg_n, int));
	else if (convert == 's')
		arg->data = ft_strdup_printf(va_arg(arg_n, char *));
	else if (convert == 'p')
	{
		arg->data = ft_ltoa_base((unsigned long int) va_arg(arg_n, void *), \
			"0123456789abcdef");
		arg->data = ft_strjoin("0x", arg->data);
		result->length += 2;
	}
	else if (convert == '%')
		arg->data = char_to_string('%');
	arg->type = convert;
	return (arg);
}

int	print_and_return(char *arg, char convert, t_opt opt)
{
	int		len;

	if (!opt.flag && !opt.width && !opt.precis)
		return (make_it_shorter(arg, convert));
	arg = precision_app(arg, convert, opt.precis);
	len = 0;
	if (convert == 'c' && !ft_strlen(arg))
	{
		if (opt.width)
			opt.width--;
		len++;
	}
	arg = flag_converter(arg, convert, opt);
	len += ft_strlen(arg);
	free(arg);
	free(opt.flag);
	return (len);
}

char	*flag_converter(char *arg, char convert, t_opt opt)
{
	char	*set;

	if (!opt.flag && opt.width)
	{
		arg = only_width_min(arg, opt.width);
		//ft_putstr(arg);
		return (arg);
	}
	set = ft_strdup("diuxX");
	if (ft_strchr(opt.flag, '0') && !(ft_strchr(opt.flag, '-')) \
		&& ft_strchr(set, convert) && !opt.precis)
		arg = zero_flag(arg, opt.width);
	if (ft_strchr(opt.flag, '+') && (convert == 'd' || convert == 'i'))
		arg = plus_flag(arg);
	if (ft_strchr(opt.flag, ' ') && !ft_strchr(opt.flag, '+') \
		&& (convert == 'd' || convert == 'i' \
			|| (convert == 's' && !ft_strlen(arg) && opt.width)))
		arg = space_flag(arg);
	if (ft_strchr(opt.flag, '#') && (convert == 'x' || convert == 'X'))
		arg = hashtag_flag(arg, convert);
	if (ft_strchr(opt.flag, '-'))
		arg = minus_flag(arg, opt.width);
	ft_putstr(arg);
	free(set);
	return (arg);
}

int	make_it_shorter(char *arg, char convert)
{
	int	result;

	if (convert == 'c' && !ft_strlen(arg))
	{
		ft_putchar('\0');
		result = 1;
	}
	else
	{
		ft_putstr(arg);
		result = ft_strlen(arg);
	}
	free(arg);
	return (result);
}

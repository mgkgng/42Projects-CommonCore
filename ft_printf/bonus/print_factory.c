/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 12:07:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_print(char convert, va_list arg_n)
{	
	if (convert == 'd' || convert == 'i')
		return (ft_itoa(va_arg(arg_n, int)));
	else if (convert == 'u')
		return (ft_itoa(va_arg(arg_n, unsigned int)));
	else if (convert == 'x')
		return (ft_itoa_base((unsigned int) va_arg(arg_n, int), 0));
	else if (convert == 'X')
		return (ft_itoa_base((unsigned int) va_arg(arg_n, int), 1));
	else if (convert == 'c')
		return (char_to_string(va_arg(arg_n, int)));
	else if (convert == 's')
		return (ft_strdup_printf(va_arg(arg_n, char *)));
	else if (convert == 'p')
		return (get_pointer((unsigned long int) va_arg(arg_n, void *)));
	else if (convert == '%')
		return (char_to_string('%'));
	/* think about ELSE
	else
		return (NULL);
		->
		if (!arg)
			return (0);
	*/
}

int	print(t_arg arg, t_opt opt)
{
	int		len;

	if (!opt.flag && !opt.width && !opt.precis)
		return (without_opt(arg));
	app_precis(&arg, opt.precis);
	if (arg.type == CONV_C && !ft_strlen(arg.print))
	{
		if (opt.width)
			opt.width--;
		len++;
	}
	app_flag(&arg, opt);
	ft_putstr(arg.print);
	return (ft_strlen(arg.print));
}

void	app_flag(t_arg *arg, t_opt opt)
{
	if (!opt.flag && opt.width)
	{
		only_width(arg, opt.width);
		return ;
	}
	if (ft_strchr(opt.flag, '0') && !(ft_strchr(opt.flag, '-')) \
		&& arg->type <= CONV_XU && !opt.precis)
		zero_flag(arg, opt.width);
	if (ft_strchr(opt.flag, '+') && arg->type == CONV_DI)
		plus_flag(arg);
	if (ft_strchr(opt.flag, ' ') && !ft_strchr(opt.flag, '+') \
		&& (arg->type == CONV_DI \
			|| (arg->type == CONV_S && !ft_strlen(arg->print) && opt.width)))
		space_flag(arg);
	if (ft_strchr(opt.flag, '#') && (arg->type == CONV_XL || arg->type == CONV_XU))
		hashtag_flag(arg);
	if (ft_strchr(opt.flag, '-'))
		minus_flag(arg, opt.width);
}

int	without_opt(t_arg arg)
{
	int	len;

	if (arg.type == CONV_C && !ft_strlen(arg.print))
	{
		ft_putchar('\0');
		return (1);
	}
	ft_putstr(arg.print);
	return (ft_strlen(arg.print));
}

int	get_argtype(char type)
{
	if (type == 'd' || type == 'i')
		return (CONV_DI);
	else if (type == 'u')
		return (CONV_U);
	else if (type == 'x')
		return (CONV_XL);
	else if (type == 'X')
		return (CONV_XU);
	else if (type == 's')
		return (CONV_S);
	else if (type == 'c')
		return (CONV_C);
	else if (type == 'p')
		return (CONV_P);
	else if (type == '%')
		return (CONV_PERC);
}

int	print_factory(const char *s, int i, va_list arg_n)
{
	t_opt	opt;
	t_arg	arg;
	int		len;

	opt.flag = get_flag(s, &i);
	opt.width = get_width(s, &i);
	opt.precis = get_precis(s, &i);
	arg.type = get_type(s[i]);
	arg.print = get_print(s[i], arg_n);
	len = print(arg, opt);
	free(arg.print);
	return (len);
}

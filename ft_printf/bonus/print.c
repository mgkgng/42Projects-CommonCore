/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 14:01:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_print(t_print *print, t_opt opt)
{
	int		len;

	if (!opt.flag && !opt.width && !opt.precis)
		return ;
	app_precis(print, opt.precis);
	app_flag(print, opt);
	free(opt.flag);
}

int	do_print(t_print print)
{
	int	len;
	
	ft_putstr(print.str);
	len = ft_strlen(print.str);
	if (!len)
		len++;
	free(print.str);
	return (len);
}

int	print_factory(const char *s, int *i, va_list arg_n)
{
	t_opt	opt;
	t_print	print;

	opt.flag = get_flag(s, i);
	opt.width = get_width(s, i);
	opt.precis = get_precis(s, i);
	print.type = get_type(s[*i]);
	print.str = get_str(s[*i], arg_n);
	get_print(&print, opt);
	return (do_print(print));
}

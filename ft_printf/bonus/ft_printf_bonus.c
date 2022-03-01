/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:49:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 19:26:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *s, ...)
{
	va_list		arg_n;
	t_len		tmp;
	int			i;
	int			len;

	va_start(arg_n, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			tmp = print_factory(s, ++i, arg_n);
			len += tmp.length;
			i = tmp.index;
		}
		else
		{
			ft_putchar(s[i++]);
			len++;
		}
	}
	va_end(arg_n);
	return (len);
}

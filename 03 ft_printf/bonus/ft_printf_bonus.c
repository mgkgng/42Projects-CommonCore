/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:49:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *s, ...)
{
	va_list		arg_n;
	int			i;
	int			len;

	va_start(arg_n, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && ++i)
			len += launch_print(s, &i, arg_n);
		else
			len += ft_putchar(s[i++]);
	}
	va_end(arg_n);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:08:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 12:25:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		arg_n;
	int			i;
	int			len;

	va_start(arg_n, s);
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '%')
			len += print(s[++i], arg_n);
		else
			len += ft_putchar(s[i]);
	}
	va_end(arg_n);
	return (len);
}

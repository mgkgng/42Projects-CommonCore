/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:08:06 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/16 11:08:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg_n;
	int			index;
	int			sum;

	index = 0;
	sum = 0;
	va_start(arg_n, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			sum += print_factory(++index, str, arg_n);
			index++;
		}
		else
		{
			ft_putchar(str[index++]);
			sum++;
		}
	}
	va_end(arg_n);
	return (sum);
}

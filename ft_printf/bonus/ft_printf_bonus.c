/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:49:47 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/15 18:50:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg_n;
	int			index;
	int			sum;
	t_value		*temp;

	index = 0;
	sum = 0;
	va_start(arg_n, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			temp = print_factory(index, str, arg_n);
			sum += temp->value;
			index = temp->index;
			free(temp);
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

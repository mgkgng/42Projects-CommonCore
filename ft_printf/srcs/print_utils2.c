/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:33:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int upper)
{
	char			*set;

	if (!upper)
		set = ft_strdup("0123456789abcdef");
	else
		set = ft_strdup("0123456789ABCDEF");
	if (n > 15)
		ft_puthex(n / 16, upper);
	ft_putchar(set[n % 16]);
	free(set);
	return (ft_nbrlen(n, 16));
}

int	ft_ptrlen(unsigned long long n)
{
	int	len;

	len = 3;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr(unsigned long long n, int on)
{
	char	*set;

	set = ft_strdup("0123456789abcdef");
	if (on)
		ft_putstr("0x");
	if (n > 15)
		ft_putptr(n / 16, 0);
	ft_putchar(set[n % 16]);
	free(set);
	return (ft_ptrlen(n));
}

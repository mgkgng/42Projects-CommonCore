/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:16:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/10 17:49:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar((int) s[i++]);
	return (i);
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

int	print_nbr_len(long long int n, t_spec spec, int base)
{
	int	minus;
	int	len;

	if (!n && !spec.precis)
		return (0);
	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus++;
	}
	len = ft_nbrlen(n, base);
	if (len < spec.precis)
		return (spec.precis + minus);
	return (len + minus);
}

int	ft_putnbr(long long int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (ft_nbrlen(n, 10));
}

int	print_nbr(long long int *n, t_spec spec)
{
	int	len;

	if (!*n && !spec.precis)
		return (0);
	len = 0;
	if (*n < 0)
	{
		ft_putchar('-');
		len++;
		*n *= -1;
	}
	len += print_precis_nbr(spec.precis, ft_nbrlen(*n, 10));
	len += ft_putnbr(*n);
	return (len);
}

int	print_unsigned(unsigned int n, t_spec spec)
{
	int	len;

	if (!n && !spec.precis)
		return (0);
	len = print_precis_nbr(spec.precis, ft_nbrlen(n, 10));
	len += ft_putnbr(n);
	return (len);
}

int	print_precis_nbr(int precis, int len)
{
	int	i;

	i = -1;
	while (len + ++i < precis)
		ft_putchar('0');
	return (i);
}

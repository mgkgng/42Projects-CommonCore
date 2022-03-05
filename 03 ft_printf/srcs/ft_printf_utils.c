/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:08:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 15:23:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
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

int	ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (ft_nbrlen(n, 10));
}

int	ft_putnbr_base(unsigned long int n, char *base, char convert)
{
	int					count;
	unsigned long int	save;
	char				*str;
	int					result;

	save = n;
	count = 1;
	if (convert == 'p')
		ft_putstr("0x");
	while (save > (unsigned long int) ft_strlen(base) - 1)
	{
		count++;
		save /= (unsigned long int) ft_strlen(base);
	}
	str = malloc(count + 1);
	str[count--] = '\0';
	while (n > (unsigned long int) ft_strlen(base) - 1)
	{
		str[count--] = base[n % (unsigned long int) ft_strlen(base)];
		n /= (unsigned long int) ft_strlen(base);
	}
	str[count] = base[n % (unsigned long int) ft_strlen(base)];
	result = ft_putstr(str);
	free(str);
	return (result);
}

// should clean it
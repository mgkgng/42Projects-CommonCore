/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:09:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 17:50:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				begin;
	int				len;
	long long int	tmp;

	tmp = n;
	len = ft_nbrlen(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	begin = 0;
	if (tmp < 0)
	{
		res[begin++] = '-';
		tmp *= -1;
	}
	res[len--] = '\0';
	while (len >= begin)
	{
		res[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (res);
}

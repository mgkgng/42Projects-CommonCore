/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:09:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 15:30:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(long long int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(long long int n)
{
	char	*res;
	int		begin;
	int		len;

	len = count_int(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	begin = 0;
	if (n < 0)
	{
		res[begin++] = '-';
		n *= -1;
	}
	res[len--] = '\0';
	while (len >= begin)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

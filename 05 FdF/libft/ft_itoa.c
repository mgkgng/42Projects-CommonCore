/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:09:04 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/27 16:54:27 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
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

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		count;

	count = count_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(count + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i++] = '-';
		n *= -1;
	}
	result[count--] = '\0';
	while (count >= i)
	{
		result[count--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:38:13 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/23 23:25:25 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(const int n)
{
	int		i;
	int		nb;

	nb = n;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(const int n, int *size)
{
	char	*dest;
	int		sign;
	int		len;
	int		nb;

	nb = n;
	if (nb < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_intlen(nb);
	if (size != NULL)
		*size = len;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	while (len != 0 && len--)
	{
		dest[len] = '0' + (nb % 10) * sign;
		nb /= 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}

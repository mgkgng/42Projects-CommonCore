/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:47:24 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/24 16:31:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	if (n == 0)
		return (0);
	while ((size_t) i < n)
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	return (0);
}

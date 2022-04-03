/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:47:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 17:43:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	if (!n)
		return (NULL);
	p = (char *) s;
	i = -1;
	while (++i < n)
		if (*(p + i)== (char) c)
			return (p + i);
	return (NULL);
}

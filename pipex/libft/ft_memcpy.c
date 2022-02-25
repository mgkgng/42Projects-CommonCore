/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:23:21 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/27 16:25:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dst_b;
	char	*src_b;

	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dst_b = (char *) dst;
	src_b = (char *) src;
	i = 0;
	while ((size_t) i < n)
	{
		dst_b[i] = src_b[i];
		i++;
	}
	return (dst);
}

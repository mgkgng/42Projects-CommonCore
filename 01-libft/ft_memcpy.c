/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:23:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:33:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_b;
	char	*src_b;

	if (!n)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dst_b = (char *) dst;
	src_b = (char *) src;
	i = 0;
	while (i < n)
	{
		dst_b[i] = src_b[i];
		i++;
	}
	return (dst);
}

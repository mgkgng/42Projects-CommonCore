/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:17:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:34:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_b;
	char	*src_b;
	size_t	i;

	if (!len)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dst_b = (char *) dst;
	src_b = (char *) src;
	i = len;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (--i >= 0)
			dst_b[i] = src_b[i];
	return (dst);
}

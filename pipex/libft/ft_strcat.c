/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:55:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 19:55:11 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	if (!dest)
		return (ft_strdup(src));
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	dest = (char *) ft_realloc(dest, dlen + slen + 1);
	/* how to do memcpy from the middle of a string ? */
	i = -1;
	while (++i < slen)
		dest[dlen + i] = src[i];
	dest[dlen + i] = '\0';
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:53:29 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 18:15:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	if (!(ft_strncmp(needle, "", ft_strlen(needle))))
		return ((char *) haystack);
	i = -1;
	nlen = ft_strlen(needle);
	while (haystack[++i] && i < len)
		if (i + nlen - 1 < len && !ft_strncmp(haystack + i, needle, nlen))
			return ((char *) haystack + i);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:53:29 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/27 16:47:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (ft_strncmp(needle, "", ft_strlen(needle)) == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		check = 1;
		if (haystack[i] == needle[j])
		{
			while (needle[j])
			{
				if (needle[j] != haystack[i + j] || i + j >= len)
					check = 0;
				j++;
			}
			if (check == 1)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}

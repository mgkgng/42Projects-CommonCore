/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:10:56 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/27 16:33:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*result;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && (size_t) i < len)
	{
		result[i] = (char) s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

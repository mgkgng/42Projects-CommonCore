/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:33:35 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 12:30:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		start;
	int 	len;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_size(s, c) + 1));
	if (!res)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		len = 0;
		while (s[start + len] && s[start + len] != c)
			len++;
		if (s[start])
			res[i++] = ft_substr(s, start, len);
		start += len;
	}
	res[i] = NULL;
	return (res);
}
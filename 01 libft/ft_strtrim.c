/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:34:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:47:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (s1[start] && ft_check_set(s1[start], set))
		start++;
	if (!(s1[start]))
		return (ft_strdup(""));
	while (ft_check_set(s1[end], set) && end >= 0)
		end--;
	if (start > end || end == 0)
		return (ft_strdup(""));
	res = malloc(end - start + 2);
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = (char) s1[start++];
	res[i] = '\0';
	return (res);
}

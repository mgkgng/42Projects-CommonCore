/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:34:44 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/31 18:05:28 by min-kang         ###   ########.fr       */
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
	char	*new;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (ft_check_set(s1[start], set) && s1[start])
		start++;
	if (!(s1[start]))
		return (ft_strdup(""));
	while (ft_check_set(s1[end], set) && end >= 0)
		end--;
	if (start > end || end == 0)
		return (ft_strdup(""));
	new = malloc(end - start + 2);
	if (new == NULL)
		return (NULL);
	while (start <= end)
		new[i++] = (char) s1[start++];
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:55:02 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/16 16:55:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	index_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			if (!s[i])
				break;
		}
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char		**result;
	char		*start;
	int			i;
	int			len;

	if (!s)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char *) * (index_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c && len++ != -1)
			s++;
		if (*(s - 1) != c)
			result[i++] = ft_substr(start, 0, len);
	}
	result[i] = 0;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strchr_set(char *s, char *set)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (set[j])
			if (s[i] == set[j++])
				return (i);
	}
	return (-1);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

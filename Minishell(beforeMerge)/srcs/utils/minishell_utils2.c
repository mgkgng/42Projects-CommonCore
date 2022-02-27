/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:54:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/16 16:54:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while ((s1[i] || s2[i]) && res == 0 && i < n)
	{
		if (s1[i] != s2[i])
			res = s1[i] - s2[i];
		i++;
	}
	return (res);
}

char	*ft_substr(char *s, int start, int len)
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
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_putstr(char *s)
{
	while (s && *s)
		write(1, s++, 1);
}

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (s1);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	if (flag)
		free(s1);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:39:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/09 14:50:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*put_line(char *r, char *buf)
{
	char	*nov;
	int		i;
	int		j;

	if (!r)
		r = ft_strdup("");
	nov = malloc(ft_strlen(r) + ft_strlen(buf) + 1);
	i = -1;
	while (r[++i])
		nov[i] = r[i];
	j = 0;
	while (buf[j])
		nov[i++] = buf[j++];
	nov[i] = '\0';
	free(r);
	return (nov);
}

char	*get_line(char **r, int pos)
{
	int		i;
	int		j;
	char	*res;
	char	*nov;

	if (pos == -1)
		return (NULL);
	res = malloc(pos + 2);
	i = -1;
	while (++i <= pos)
		res[i] = (*r)[i];
	res[i] = '\0';
	nov = NULL;
	if (i < ft_strlen(*r) - 1)
	{
		nov = malloc(ft_strlen(*r) - i);
		j = 0;
		while ((*r)[i])
			nov[j++] = (*r)[i++];
		nov[j] = '\0';
	}
	free(*r);
	*r = nov;
	return (res);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	find_endl(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

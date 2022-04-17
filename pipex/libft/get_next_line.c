/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:39:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 19:30:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_endl(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_substr(char *s, int start, int end)
{
	char	*res;
	int		i;

	if (start > end)
		return (NULL);
	res = malloc(end - start + 2);
	i = -1;
	while (++i + start <= end)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}

void	put_buf(char **r, char *buf)
{
	char	*nov;
	int		i;
	int		j;

	if (!*r)
		*r = ft_substr("", 0, 0);
	nov = malloc(ft_strlen(*r) + ft_strlen(buf) + 1);
	i = -1;
	while ((*r)[++i])
		nov[i] = (*r)[i];
	j = 0;
	while (buf[j])
		nov[i++] = buf[j++];
	nov[i] = '\0';
	free(*r);
	*r = nov;
}

char	*get_line(char **r)
{
	char	*res;
	char	*nov;
	int		pos;

	if (!*r)
		return (NULL);
	pos = find_endl(*r);
	if (pos == -1)
		pos = ft_strlen(*r) - 1;
	res = ft_substr(*r, 0, pos);
	nov = ft_substr(*r, pos + 1, ft_strlen(*r) - 1);
	free(*r);
	*r = nov;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*r;
	int			bytes;
	char		buf[BUFFER_SIZE + 1];

	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		put_buf(&r, buf);
		if (find_endl(r) != -1)
			return (get_line(&r));
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (get_line(&r));
}

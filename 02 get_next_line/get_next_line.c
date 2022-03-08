/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:38:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/08 12:35:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*get_line(char **r, int r_byte)
{
	char	*res;

	if (find_endl(*r) != -1)
	{
		if (find_endl(*r) + 1 == ft_strlen(*r))
		{
			res = ft_strndup(*r, ft_strlen(*r));
			free(*r);
			*r = NULL;
			return (res);
		}
		res = ft_strndup(*r, find_endl(*r) + 1);
		*r = ft_cut(*r, find_endl(*r) + 1);
		return (res);
	}
	else if (!r_byte && ft_strlen(*r))
	{
		res = ft_strndup(*r, ft_strlen(*r));
		free(*r);
		*r = NULL;
		return (res);
	}
	return (NULL);
}*/

char	*get_next_line(int fd)
{
	int			i;
	static char	*r;
	char		*res;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	i = read(fd, r, BUFFER_SIZE);
	while (i > 0 || r)
	{
		r[i] = '\0';
		res = get_line(r, find_endl(r));
		if (res)
			return (res);
	}
	return (NULL);
}

t /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:38:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/10 12:25:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*r[OPEN_MAX];
	int			bytes;
	char		buf[BUFFER_SIZE + 1];

	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		put_buf(&r[fd], buf);
		if (find_endl(r[fd]) != -1)
			return (get_line(&r[fd]));
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (get_line(&r[fd]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:38:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/10 12:25:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

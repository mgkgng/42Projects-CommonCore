/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:38:09 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/05 16:07:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_to_print(int r_byte, char **r_data)
{
	char	*result;

	if (nl_index(*r_data) != -1)
	{
		if ((size_t) nl_index(*r_data) + 1 == ft_strlen(*r_data))
		{
			result = ft_strndup(*r_data, ft_strlen(*r_data));
			free(*r_data);
			*r_data = NULL;
			return (result);
		}
		result = ft_strndup(*r_data, nl_index(*r_data) + 1);
		*r_data = ft_cut(*r_data, nl_index(*r_data) + 1);
		return (result);
	}
	else if (!r_byte && ft_strlen(*r_data))
	{
		result = ft_strndup(*r_data, ft_strlen(*r_data));
		free(*r_data);
		*r_data = NULL;
		return (result);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*r_data[OPEN_MAX];
	int			r_byte;
	char		buf[BUFFER_SIZE + 1];
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	r_byte = 1;
	while (r_byte)
	{
		r_byte = read(fd, buf, BUFFER_SIZE);
		if (r_byte < 0 || (r_byte == 0 && !r_data[fd]))
			return (NULL);
		if (r_byte > 0)
		{
			buf[r_byte] = '\0';
			r_data[fd] = ft_strjoin(r_data[fd], buf);
		}
		result = line_to_print(r_byte, &r_data[fd]);
		if (result != NULL)
			return (result);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:38:41 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/01 14:58:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_to_print(char **r_data, int r_byte)
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
	static char	*r_data;
	int			r_byte;
	char		buf[BUFFER_SIZE + 1];
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	r_byte = 1;
	while (r_byte)
	{
		r_byte = read(fd, buf, BUFFER_SIZE);
		if (r_byte < 0 || (r_byte == 0 && !r_data))
			return (NULL);
		if (r_byte > 0)
		{
			buf[r_byte] = '\0';
			r_data = ft_strjoin(r_data, buf);
		}
		result = line_to_print(&r_data, r_byte);
		if (result != NULL)
			return (result);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:42:42 by gphilipp          #+#    #+#             */
/*   Updated: 2022/01/02 14:10:39 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	fs_open(char *path, int *length, int *newline)
{
	int		fd;
	char	src;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	*length = 0;
	*newline = 0;
	while (read(fd, &src, 1))
	{
		if (src == '\n')
			(*newline)++;
		(*length)++;
	}
	close(fd);
	return (1);
}

static char	*fs_read(char *path, int length)
{
	int		i;
	int		fd;
	char	*content;
	char	src;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	content = malloc(sizeof(char) * (length + 1));
	if (content == 0)
		return (0);
	while (read(fd, &src, 1))
	{
		content[i] = src;
		i++;
	}
	content[length] = '\0';
	close(fd);
	return (content);
}

char	*ft_get_content(char *path)
{
	int			length;
	char		*content;
	int			newline;

	if (fs_open(path, &length, &newline) == 0)
		return (NULL);
	content = fs_read(path, length);
	return (content);
}

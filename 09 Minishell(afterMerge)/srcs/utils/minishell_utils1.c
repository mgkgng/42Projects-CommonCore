/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:51:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 21:37:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while ((size_t) i < n)
		str[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*result;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((size_t) i < size * count)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
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

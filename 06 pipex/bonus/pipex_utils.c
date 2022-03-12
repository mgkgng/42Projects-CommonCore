/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:10:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 21:08:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

char	*get_data(int fd)
{
	char	*r_data;
	char	*result;

	result = NULL;
	r_data = get_next_line(fd);
	while (r_data)
	{
		result = ft_strjoin_gnl(result, r_data);
		free(r_data);
		r_data = get_next_line(fd);
	}
	free(r_data);
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_free(t_cmd *result)
{
	free(result->args);
	free(result->cmd);
	perror("Command name error");
	unlink("here_doc");
	exit(EXIT_FAILURE);
}

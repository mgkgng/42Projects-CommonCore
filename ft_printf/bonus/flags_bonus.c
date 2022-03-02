/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:24:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 12:30:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*zero_flag(char *arg, int width)
{
	char	*res;
	int		i;
	int		j;

	if (ft_strlen(arg) >= width)
		return (arg);
	res = ft_calloc(width + 1, sizeof(char));
	i = 0;
	j = 0;
	if (arg[0] == '-')
	{
		res[i++] = '-';
		j++;
	}
	while (i < width - ft_strlen(arg + j))
		res[i++] = '0';
	while (arg[j])
		res[i++] = arg[j++];
	res[i] = '\0';
	free(arg);
	return (res);
}

char	*plus_flag(char *arg)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	if (ft_atoi(arg) >= 0)
		j++;
	res = ft_calloc(ft_strlen(arg) + 1 + j, sizeof(char));
	i = 0;
	if (j)
		res[i++] = '+';
	while (arg[++i])
		res[i + j] = arg[i];
	res[i + j] = '\0';
	free(arg);
	return (res);
}

char	*space_flag(char *arg)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	if (ft_atoi(arg) >= 0)
		j++;
	res = ft_calloc(ft_strlen(arg) + 1 + j, sizeof(char));
	i = 0;
	if (j)
		res[i++] = ' ';
	while (arg[++i])
		res[i + j] = arg[i];
	res[i + j] = '\0';
	free(arg);
	return (res);
}

char	*hashtag_flag(char *arg, int convert)
{
	char	*res;
	int		i;

	if (ft_strncmp(arg, "0", ft_strlen(arg)) == 0)
	{
		free(arg);
		return (ft_strdup("0"));
	}
	res = ft_calloc(ft_strlen(arg) + 3, sizeof(char));
	res[0] = '0';
	if (convert == CONV_XL)
		res[1] = 'x';
	else
		res[1] = 'X';
	i = -1;
	while (arg[++i])
		res[i + 2] = arg[i];
	res[i + 2] = '\0';
	free(arg);
	return (res);
}

char	*minus_flag(char *arg, int width)
{
	char	*res;
	int		i;

	if (ft_strlen(arg) >= width)
		return (arg);
	else
	{
		res = ft_calloc(width + 1, sizeof(char));
		i = -1;
		while (arg[++i])
			res[i] = arg[i];
		while (i < width)
			res[i++] = ' ';
	}
	res[i] = '\0';
	free(arg);
	return (res);
}

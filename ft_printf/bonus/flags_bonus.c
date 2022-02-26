/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:24:45 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/15 18:24:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*zero_flag(char *arg, int width_min)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(arg) >= (size_t) width_min)
		return (arg);
	else
	{
		result = malloc(width_min + 1);
		if (arg[j] == '-')
		{
			result[i++] = '-';
			j++;
		}
		while (i < width_min - (int) ft_strlen(arg + j))
			result[i++] = '0';
		while (arg[j])
			result[i++] = arg[j++];
	}
	result[i] = '\0';
	free(arg);
	return (result);
}

char	*plus_flag(char *arg)
{
	char	*result;
	int		i;

	i = -1;
	if (ft_atoi(arg) >= 0)
	{
		result = malloc(ft_strlen(arg) + 2);
		result[0] = '+';
		while (arg[++i])
			result[i + 1] = arg[i];
		result[i + 1] = '\0';
	}
	else
	{
		result = malloc(ft_strlen(arg) + 1);
		while (arg[++i])
			result[i] = arg[i];
		result[i] = '\0';
	}
	free(arg);
	return (result);
}

char	*space_flag(char *arg)
{
	char	*result;
	int		i;

	i = -1;
	if (ft_atoi(arg) >= 0)
	{
		result = malloc(ft_strlen(arg) + 2);
		result[0] = ' ';
		while (arg[++i])
			result[i + 1] = arg[i];
		result[i + 1] = '\0';
	}
	else
	{
		result = malloc(ft_strlen(arg) + 1);
		while (arg[++i])
			result[i] = arg[i];
		result[i] = '\0';
	}
	free(arg);
	return (result);
}

char	*hashtag_flag(char *arg, char convert)
{
	char	*result;
	int		i;

	if (ft_strncmp(arg, "0", ft_strlen(arg)) == 0)
	{
		free(arg);
		return (ft_strdup("0"));
	}
	i = -1;
	result = malloc(ft_strlen(arg) + 3);
	result[0] = '0';
	if (convert == 'x')
		result[1] = 'x';
	else
		result[1] = 'X';
	while (arg[++i])
		result[i + 2] = arg[i];
	result[i + 2] = '\0';
	free(arg);
	return (result);
}

char	*minus_flag(char *arg, int width_min)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(arg) >= (size_t) width_min)
		return (arg);
	else
	{
		result = malloc(width_min + 1);
		while (arg[j])
			result[i++] = arg[j++];
		while (i < width_min)
			result[i++] = ' ';
	}
	result[i] = '\0';
	free(arg);
	return (result);
}

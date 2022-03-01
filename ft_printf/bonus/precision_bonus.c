/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 19:59:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*precision_app(char *arg, char convert, int precis)
{
	char	*result;
	char	*set;

	set = ft_strdup("diuxX");
	if (!precis || (!ft_strchr(set, convert) && convert != 's'))
	{
		free(set);
		return (arg);
	}
	if (ft_strchr(set, convert))
		result = ft_precision_num(arg, precis);
	else
		result = ft_precision_str(arg, precis);
	free(arg);
	free(set);
	return (result);
}

char	*ft_precision_num(char *arg, int precis)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (arg[j] == '-')
		precis++;
	if (precis == -1)
		precis++;
	if (!precis && !ft_strncmp(arg, "0", ft_strlen(arg)))
		return(ft_strdup(""));
	if (ft_strlen(arg) >= precis)
		return(ft_strdup(arg));
	else
	{
		res = malloc(precis + 1);
		if (arg[j] == '-')
			res[i++] = arg[j++];
		while (i < precis - ft_strlen(arg + j))
			res[i++] = '0';
		while (arg[j])
			res[i++] = arg[j++];
		res[i] = '\0';
	}
	return (res);
}

char	*ft_precision_str(char *arg, int precis)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (precis == -1)
		return (ft_strdup(""));
	else if (ft_strlen(arg) <= precis)
		return (ft_strdup(arg));
	else
	{
		res = malloc(precis + 1);
		while (i < precis)
			res[i++] = arg[j++];
	}
	res[i] = '\0';
	return (res);
}

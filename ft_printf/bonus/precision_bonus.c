/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/15 18:17:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*precision_app(char *arg, char convert, int precision)
{
	char	*result;
	char	*set;

	set = ft_strdup("diuxX");
	if (!precision || (!ft_strchr(set, convert) && convert != 's'))
	{
		free(set);
		return (arg);
	}
	if (ft_strchr(set, convert))
		result = ft_precision_num(arg, precision);
	else
		result = ft_precision_str(arg, precision);
	free(arg);
	free(set);
	return (result);
}

char	*ft_precision_num(char *arg, int precision)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (arg[j] == '-')
		precision++;
	if (precision == -1)
		precision++;
	if (!precision && !ft_strncmp(arg, "0", ft_strlen(arg)))
		return(ft_strdup(""));
	if (ft_strlen(arg) >= (size_t) precision)
		return(ft_strdup(arg));
	else
	{
		result = malloc(precision + 1);
		if (arg[j] == '-')
			result[i++] = arg[j++];
		while (i < precision - (int) ft_strlen(arg + j))
			result[i++] = '0';
		while (arg[j])
			result[i++] = arg[j++];
		result[i] = '\0';
	}
	return (result);
}

char	*ft_precision_str(char *arg, int precision)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (precision == -1)
		return (ft_strdup(""));
	else if (ft_strlen(arg) <= (size_t) precision)
		return (ft_strdup(arg));
	else
	{
		result = malloc(precision + 1);
		while (i < precision)
			result[i++] = arg[j++];
	}
	result[i] = '\0';
	return (result);
}

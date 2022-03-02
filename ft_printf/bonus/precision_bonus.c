/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 11:51:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*app_precis_num(char *print, int precis)
{
	char	*res;
	int		i;
	int		j;

	if (*print == '-')
		precis++;
	if (precis == -1)
		precis++;
	if (ft_strlen(print) >= precis)
		return (print);
	else if (!precis && !ft_strncmp(print, "0", ft_strlen(print)))
		res = ft_strdup("");
	else
	{
		i = 0;
		j = 0;
		res = ft_calloc(precis + 1, sizeof(char));
		if (print[j] == '-')
			res[i++] = print[j++];
		while (i < precis - ft_strlen(print + j))
			res[i++] = '0';
		while (print[j])
			res[i++] = print[j++];
		res[i] = '\0';
	}
	free(print);
	return (res);
}

char	*app_precis_str(char *print, int precis)
{
	char	*res;
	int		i;

	if (ft_strlen(print) <= precis)
		return (print);
	if (precis == -1)
		res = ft_strdup("");
	else
	{
		res = malloc(precis + 1);
		i = -1;
		while (++i < precis)
			res[i] = print[i];
		res[i] = '\0';
	}
	free(print);
	return (res);
}

void	app_precis(t_arg *arg, int precis)
{
	char	*res;

	if (!precis || (arg->type > CONV_S))
		return (arg);
	else if (arg->type == CONV_S)
		arg->print = app_precis_str(arg, precis);
	else
		arg->print = app_precis_num(arg, precis);
}
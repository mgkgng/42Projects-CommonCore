/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 14:08:53 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	app_precis_num(t_print *print, int precis)
{
	char	*nov;
	int		i;
	int		j;

	if (*(print->str) == '-')
		precis++;
	if (precis == -1)
		precis++;
	if (ft_strlen(print->str) >= precis)
		return ;
	else if (!precis && !ft_strncmp(print->str, "0", ft_strlen(print->str)))
		nov = ft_strdup("");
	else
	{
		i = 0;
		j = 0;
		nov = ft_calloc(precis + 1, sizeof(char));
		if (print->str[j] == '-')
			nov[i++] = print[j++];
		while (i < precis - ft_strlen(print->str + j))
			nov[i++] = '0';
		while (print->str[j])
			nov[i++] = print->str[j++];
		nov[i] = '\0';
	}
	free(print->str);
	print->str = nov;

}

void	app_precis_str(t_print *print, int precis)
{
	char	*nov;
	int		i;

	if (ft_strlen(print->str) <= precis)
		return ;
	if (precis == -1)
		nov = ft_strdup("");
	else
	{
		nov = ft_calloc(precis + 1, sizeof(char));
		i = -1;
		while (++i < precis)
			nov[i] = print->str[i];
		nov[i] = '\0';
	}
	free(print->str);
	print->str = nov;
}

void	app_precis(t_print *print, int precis)
{
	char	*nov;

	if (!precis || (print->type > CONV_S))
		return ;
	else if (print->type == CONV_S)
		app_precis_str(print, precis);
	else
		app_precis_num(print, precis);
}
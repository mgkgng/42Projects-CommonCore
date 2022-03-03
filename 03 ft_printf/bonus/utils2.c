/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:13:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 15:56:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*dup_string(char *s)
{
	int		i;
	char	*result;

	if (!s)
		return (ft_strdup("(null)"));
	result = malloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

void	ft_printstr(t_print print)
{
	int	i;

	if (print.str[0] == '\0' && print.type == CONV_C)
		ft_putchar(0);
	else
		ft_putstr(print.str);
}

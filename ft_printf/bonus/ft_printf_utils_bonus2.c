/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:24:14 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/17 13:27:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strdup_printf(char *s)
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

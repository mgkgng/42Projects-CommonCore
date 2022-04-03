/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:34:35 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

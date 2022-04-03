/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:25:56 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	if (!c)
		return (s + ft_strlen(s));
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (s + i);
	return (0);
}

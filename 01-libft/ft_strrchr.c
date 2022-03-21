/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:30:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:43:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c == 0)
		return ((char *) s + ft_strlen(s));
	i = ft_strlen(s);
	while (--i >= 0)
		if (s[i] == (char) c)
			return ((char *) s + i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:41:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 18:06:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	if (!n)
		return (0);
	while (n-- > 0)
		if (*p_s1++ != *p_s2++)
			return (p_s1[-1] - p_s2[-1]);
	return (0);
}

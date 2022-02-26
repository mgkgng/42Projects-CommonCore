/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:01:39 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/24 22:06:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*result;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((size_t) i < size * count)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

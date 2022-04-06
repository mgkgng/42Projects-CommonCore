/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:04:19 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:41:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (res == NULL)
		return (NULL);
	res->nb = (int) content;
	res->next = NULL;
	return (res);
}

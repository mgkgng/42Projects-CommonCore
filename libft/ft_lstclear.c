/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:14:55 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/30 19:58:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*temp;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		temp = begin -> next;
		ft_lstdelone(begin, del);
		begin = temp;
	}
	*lst = NULL;
}

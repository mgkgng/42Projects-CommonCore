/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:14:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:25:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		tmp = begin -> next;
		ft_lstdelone(begin, del);
		begin = tmp;
	}
	*lst = NULL;
}

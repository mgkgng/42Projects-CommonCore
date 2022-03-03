/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:22:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 18:29:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	lst = lst->next;
	result = begin;
	while (lst)
	{
		begin->next = ft_lstnew(f(lst->content));
		begin = begin->next;
		if (!begin)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		lst = lst->next;
	}
	begin->next = NULL;
	return (result);
}

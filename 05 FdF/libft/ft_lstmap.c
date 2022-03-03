/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:22:39 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/27 14:43:36 by min-kang         ###   ########.fr       */
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
		if (begin == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		lst = lst->next;
	}
	begin->next = 0;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:22:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 17:54:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	void	*ptr;

	if (!lst || !f)
		return (NULL);
	begin = NULL; 
	while (lst)
	{
		ptr = f(lst->content);
		if (!ptr)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, ft_lstnew(ptr));
		lst = lst->next;
	}
	return (begin);
}

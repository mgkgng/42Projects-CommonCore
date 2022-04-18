/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 13:42:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	min_index_put(t_list **lst, int min, int min_index)
{
	t_list	*begin;

	begin = *lst;
	while ((*lst)->nb != min && *lst)
		*lst = (*lst)->next;
	(*lst)->pos = min_index;
	*lst = begin;
}

void	put_pos(t_list **lst)
{
	int	index;
	int	min;
	int	size;

	index = 0;
	size = ft_lstsize(*lst);
	min = first_min_find(*lst);
	min_index_put(lst, min, index++);
	while (index < size)
	{
		min = next_min_find(*lst, min);
		min_index_put(lst, min, index++);
	}
}*/

void	put_index(t_list **lst)
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = *lst;
	while (*lst)
	{
		(*lst)->index = i++;
		(*lst) = (*lst)->next;
	}
	*lst = begin;
}

t_index	get_chunk(t_list *lst)
{
	t_index	res;
	t_index	tmp;
	int		dist;

	dist = 0;
	tmp.begin = lst->index;
	res.begin = 0;
	res.end = 0;
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
		{
			tmp.end = lst->next->index;
			if (dist < tmp.end - tmp.begin)
			{
				dist = tmp.end - tmp.begin;
				res.begin = tmp.begin;
				res.end = tmp.end;
			}
		}
		else
			tmp.begin = lst->next->index;
		lst = lst->next;
	}
	return (res);
}

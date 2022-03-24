/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:23:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_index_put(t_stack **lst, int min, int min_index)
{
	t_stack	*begin;

	begin = *lst;
	while ((*lst)->content != min && *lst)
		*lst = (*lst)->next;
	(*lst)->index = min_index;
	*lst = begin;
}

void	put_index(t_stack **lst)
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
}

void	swap_index(t_stack **lst)
{
	t_stack	*begin;
	int		i;

	i = 0;
	begin = *lst;
	while (*lst)
	{
		(*lst)->swap_index = i++;
		(*lst) = (*lst)->next;
	}
	*lst = begin;
}

t_stack	*new_stack(t_stack *lst)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	res->content = lst->content;
	res->index = lst->index;
	res->swap_index = lst->swap_index;
	return (res);
}
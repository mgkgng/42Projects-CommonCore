/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 00:37:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_index_put(t_list **lst, int min, int min_index)
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
}

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

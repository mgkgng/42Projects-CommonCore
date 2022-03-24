/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:18:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index	get_the_biggest_chunk(t_list *lst)
{
	t_index	result;
	t_index	tmp;
	int		dist;

	dist = 0;
	tmp.start = lst->swap_index;
	result.start = 0;
	result.end = 0;
	while (lst->next)
	{
		if (lst->index < lst->next->index)
		{
			tmp.end = lst->next->swap_index;
			if (dist < tmp.end - tmp.start)
			{
				dist = tmp.end - tmp.start;
				result.start = tmp.start;
				result.end = tmp.end;
			}
		}
		else
			tmp.start = lst->next->swap_index;
		lst = lst->next;
	}
	return (result);
}

int	chunk_limit(t_list *lst, t_index chunk, int i)
{
	int		result;
	int		count;

	result = ft_lstsize(lst) * i / 3;
	count = 0;
	while (lst && lst->swap_index <= chunk.end)
	{
		if (lst->swap_index >= chunk.start && lst->index < result)
			count++;
		lst = lst->next;
	}
	return (result - count);
}

void	push_or_rotate(t_list **lst_a, t_list **lst_b, t_index chunk, int i)
{	
	if (!i)
	{
		if ((*lst_a)->swap_index < chunk.start
			|| (*lst_a)->swap_index > chunk.end)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
	else
	{
		if (((*lst_a)->swap_index < chunk.start
				|| (*lst_a)->swap_index > chunk.end)
			&& (*lst_a)->index < chunk.entire * i / 3)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
}

void	push_everything_in_b(t_list **lst_a, t_list **lst_b, t_index chunk)
{
	int	chunk1;
	int	chunk2;

	chunk.entire = ft_lstsize(*lst_a);
	if (chunk.entire <= 99)
		while (*lst_a && ft_lstsize(*lst_a) != chunk.size)
			push_or_rotate(lst_a, lst_b, chunk, 0);
	else
	{
		chunk1 = chunk_limit(*lst_a, chunk, 1);
		chunk2 = chunk_limit(*lst_a, chunk, 2);
		while (ft_lstsize(*lst_b) < chunk1)
			push_or_rotate(lst_a, lst_b, chunk, 1);
		while (ft_lstsize(*lst_b) < chunk2)
			push_or_rotate(lst_a, lst_b, chunk, 2);
		while (ft_lstsize(*lst_a) != chunk.size)
			push_or_rotate(lst_a, lst_b, chunk, 0);
	}
}

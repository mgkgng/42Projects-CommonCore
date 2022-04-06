/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:27:10 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index	get_chunk(t_stack *st)
{
	t_index	res;
	t_index	tmp;
	int		dist;

	dist = 0;
	tmp.start = st->index;
	res.start = 0;
	res.end = 0;
	while (st->next)
	{
		if (st->pos < st->next->pos)
		{
			tmp.end = st->next->index;
			if (dist < tmp.end - tmp.start)
			{
				dist = tmp.end - tmp.start;
				res.start = tmp.start;
				res.end = tmp.end;
			}
		}
		else
			tmp.start = st->next->index;
		st = st->next;
	}
	return (res);
}

int	chunk_limit(t_stack *st, t_index chunk, int i)
{
	int		res;
	int		count;

	res = ft_lstsize(st) * i / 3;
	count = 0;
	while (st && st->index <= chunk.end)
	{
		if (st->index >= chunk.start && st->pos < res)
			count++;
		st = st->next;
	}
	return (res - count);
}

void	push_or_rotate(t_stack **lst_a, t_stack **lst_b, t_index chunk, int i)
{	
	if (!i)
	{
		if ((*lst_a)->index < chunk.start
			|| (*lst_a)->index > chunk.end)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
	else
	{
		if (((*lst_a)->index < chunk.start
				|| (*lst_a)->index > chunk.end)
			&& (*lst_a)->pos < chunk.entire * i / 3)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
}

void	push_everything_in_b(t_stack **lst_a, t_stack **lst_b, t_index chunk)
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

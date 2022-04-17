/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 01:14:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	chunk_limit(t_list *l, t_index chunk, int i)
{
	int		res;
	int		count;

	res = ft_lstsize(l) * i / 3;
	count = 0;
	while (l && l->index <= chunk.end)
	{
		if (l->index >= chunk.begin && l->pos < res)
			count++;
		l = l->next;
	}
	return (res - count);
}

void	push_or_rotate(t_stack *stack, t_index chunk, int limit, int divide)
{
	int	i;
	int	limit;

	i = -1;
	if (!divide)
	{
		if (stack->a->index < chunk.begin
			|| stack->a->index > chunk.end)
			ops(stack, "pb", 1);
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
	else
	{
		if (((*lst_a)->index < chunk.begin
				|| (*lst_a)->index > chunk.end)
			&& (*lst_a)->pos < ft_lstsize(&stack->a) * chunk / 3)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
}

void	push_everything_in_b(t_stack *stack, t_index chunk)
{
	if (ft_lstsize(&stack->a) < 100)
		while (stack->a && ft_lstsize(stack->a) != chunk.size)
			push_or_rotate(stack, chunk, 0);
	else
	{
		while (ft_lstsize(stack->b) < chunk_limit(stack->a, chunk, 1))
			push_or_rotate(stack, chunk, 1);
		while (ft_lstsize(stack->b) < 
			push_or_rotate(stack, chunk, 2);
		while (ft_lstsize(*lst_a) != chunk.size)
			push_or_rotate(lst_a, lst_b, chunk, 0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:28:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	that_is_the_place(t_stack *a, t_stack *b)
{
	t_stack	*last_stack;

	if (!a || !b)
		return (0);
	last_stack = ft_lstlast(a);
	if (a->pos > b->pos && a->pos < last_stack->pos)
		return (1);
	else if (a->pos > b->pos && b->pos > last_stack->pos)
		return (1);
	else if (a->pos < last_stack->pos && b->pos > last_stack->pos)
		return (1);
	return (0);
}

int	that_is_the_place2(int a, int last_a, int b)
{
	if (a > b && a < last_a)
		return (1);
	else if (a > b && b > last_a)
		return (1);
	else if (a < last_a && b > last_a)
		return (1);
	return (0);
}

void	rotate_at_the_same_time(t_stack **a, t_stack **b, t_move **move)
{
	while ((*move)->ra > 0 && (*move)->rb > 0)
	{
		rotate_rotate(a, b);
		(*move)->ra--;
		(*move)->rb--;
	}
	while ((*move)->rra > 0 && (*move)->rrb > 0)
	{
		reverse_rotate_rotate(a, b);
		(*move)->rra--;
		(*move)->rrb--;
	}
}

void	make_move(t_stack **a, t_stack **b, t_move *move)
{
	rotate_at_the_same_time(a, b, &move);
	while (move->ra > 0)
	{
		rotate_a(a);
		move->ra--;
	}
	while (move->rb > 0)
	{
		rotate_b(b);
		move->rb--;
	}
	while (move->rra > 0)
	{
		reverse_rotate_a(a);
		move->rra--;
	}
	while (move->rrb > 0)
	{
		reverse_rotate_b(b);
		move->rrb--;
	}
	push_a(a, b);
}

void	ft_dirty(t_stack *a, t_stack *b, t_dirty *dirty)
{
	dirty->size_a = ft_lstsize(a);
	dirty->size_b = ft_lstsize(b);
	dirty->begin_a = a;
	dirty->begin_b = b;
	dirty->min = INT32_MAX;
	dirty->last_a = ft_lstlast(a)->pos;
}

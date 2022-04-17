/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 01:36:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_condition(int first_a, int last_a, int first_b)
{
	if (first_a > first_b && first_a < last_a)
		return (1);
	else if (first_a > first_b && first_b > last_a)
		return (1);
	else if (first_a < last_a && first_b > last_a)
		return (1);
	return (0);
}

void	rotate_at_the_same_time(t_stack *stack, t_move **move)
{
	while ((*move)->ra > 0 && (*move)->rb > 0)
	{
		ops(stack, 5, "rr");
		(*move)->ra--;
		(*move)->rb--;
	}
	while ((*move)->rra > 0 && (*move)->rrb > 0)
	{
		ops(stack, 8, "rrr");
		(*move)->rra--;
		(*move)->rrb--;
	}
}

void	make_move(t_stack *stack, t_move *move)
{
	rotate_at_the_same_time(stack, &move);
	while (move->ra > 0)
	{
		ops(stack, 3, "ra");
		move->ra--;
	}
	while (move->rb > 0)
	{
		ops(stack, 4, "rb");
		move->rb--;
	}
	while (move->rra > 0)
	{
		ops(stack, 6, "rra");
		move->rra--;
	}
	while (move->rrb > 0)
	{
		ops(stack, 7, "rrb");
		move->rrb--;
	}
	ops(stack, 9, "pa");
}

void	ft_dirty(t_list *a, t_list *b, t_dirty *dirty)
{
	dirty->size_a = ft_lstsize(a);
	dirty->size_b = ft_lstsize(b);
	dirty->begin_a = a;
	dirty->begin_b = b;
	dirty->min = INT32_MAX;
}

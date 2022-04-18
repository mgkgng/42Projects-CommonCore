/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 14:21:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_move(t_move move, t_move *opt)
{
	if (move.rra)
		move.ra = 0;
	if (move.rrb)
		move.rb = 0;
	move.sum = move.ra + move.rb + move.rra + move.rrb;
	if (opt->sum < move.sum)
	{
		opt->sum = move.sum;
		opt->ra = move.ra;
		opt->rra = move.rra;
		opt->rb = move.rb;
		opt->rrb = move.rrb;
	}
}

void	rotate_both(t_stack *stack, t_move *move)
{
	while (move->ra > 0 && move->rb > 0)
	{
		ops(stack, 5, "rr");
		move->ra--;
		move->rb--;
	}
	while (move->rra > 0 && move->rrb > 0)
	{
		ops(stack, 8, "rrr");
		move->rra--;
		move->rrb--;
	}
}

void	make_move(t_stack *stack, t_move move)
{
	rotate_both(stack, &move);
	while (move.ra > 0)
	{
		ops(stack, 3, "ra");
		move.ra--;
	}
	while (move.rb > 0)
	{
		ops(stack, 4, "rb");
		move.rb--;
	}
	while (move.rra > 0)
	{
		ops(stack, 6, "rra");
		move.rra--;
	}
	while (move.rrb > 0)
	{
		ops(stack, 7, "rrb");
		move.rrb--;
	}
	ops(stack, 9, "pa");
}

t_move	define_move(t_stack *stack, int sizeA, int sizeB)
{
	t_move	res;
	int		indexA;
	int		indexB;
	int		i;

	ft_bzero(&res, sizeof(t_move));
	indexA = zero_find(stack->a);
	indexB = zero_find(stack->b);
	if (indexA <= sizeA / 2)
		res.ra = indexA;
	else
		res.rra = sizeA - indexA;
	if (indexB <= sizeB / 2)
		res.rb = indexB;
	else
		res.rra = sizeB - indexB;
	 
}

t_move	get_shortest(t_stack *stack)
{
	t_move	shortest;
	t_list	*beginA;

	beginA = stack->a;
	while (stack->b)
	{
		stack->a = beginA;
		while (stack->a)
		{
			if (push_condition(stack->a->nb, ft_lstlast(stack->a)->nb, stack->b->nb))
			{
				compare_move(define_move(stack, ft_lstsize(stack->a), ft_lstsize(stack->b)), &shortest);
				break;
			}
			stack->a = stack->a->next;
		}
		stack->b = stack->b->next;
	}
	return (shortest);
}
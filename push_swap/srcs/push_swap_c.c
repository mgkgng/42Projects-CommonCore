/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 01:47:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opt_define(t_move move, t_move *opt)
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

t_move	get_move(t_stack *stack, t_dirty *dirty)
{
	t_move	move;
	t_move	shortest;

	//ATTENTION: IL FAUT INITIALISER LES T-MOVES
	stack->a = dirty->begin_a;
	while (stack->b)
	{
		while (stack->a)
		{
			if (push_condition(stack->a->nb, ft_lstlast(stack->a)->nb, stack->b->nb))
				opt_define(move, &shortest);
			stack->a = stack->a->next;
			if (stack->a)
			{
				move.ra = stack->a->index;
				if (stack->a->index > dirty->size_a / 2)
					move.rra = dirty->size_a - stack->a->index;
			}
		}
		stack->b = stack->b->next;
		ft_bzero(&move, sizeof(t_move));
		if (stack->b)
		{
			if (stack->b->index < dirty->size_b / 2)
				move.rb = stack->b->index;
			else
				move.rrb = dirty->size_b - stack->b->index;
		}
	}
	return (shortest);
}

void	optimal_move(t_stack *stack)
{
	t_move	move_to_make;

	if (!stack->a || !stack->b)
		return ;
	ft_dirty(*lst_a, *lst_b, &dirty);
	move_to_make = get_move(stack, &move_to_make);
	*lst_a = dirty.begin_a;
	*lst_b = dirty.begin_b;
	make_move(lst_a, lst_b, move);
}

void	push_everything_back_in_a(t_list **lst_a, t_list **lst_b)
{
	while (*lst_b)
	{
		if (that_is_the_place(*lst_a, *lst_b))
			push_a(lst_a, lst_b);
		else
		{
			swap_index(lst_a);
			swap_index(lst_b);
			optimal_move(lst_a, lst_b);
		}
	}
}

void	get_a_in_order(t_stack *stack)
{
	int	size;

	if (stack->a->pos == find_min(stack->a))
		return ;
	put_index(&stack->a);
	size = ft_lstsize(stack->a);
	if (stack->a->pos < size / 2)
		while (stack->a->pos != 0)
			ops(stack, 6, "rra");
	else
		while (stack->a->pos != 0)
			ops(stack, 3, "ra");
}

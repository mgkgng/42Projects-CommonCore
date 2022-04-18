/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 11:49:02 by min-kang         ###   ########.fr       */
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


void	push_everything_back_in_a(t_stack *stack)
{
	while (stack->b)
		if (push_condition(stack->a->nb, ft_lstlast(stack->a)->nb, stack->b->nb))
			ops(stack, 9, "pa");
		else
		{
			put_index(stack->a);
			put_index(stack->b);
			make_move(stack, get_shortest(stack));
		}
	}
}

void	get_a_in_order(t_stack *stack)
{
	int	size;
	int	minIndex;
	int	minValue;

	minIndex = find_min(stack->a, 0);
	if (!minIndex)
		return ;
	put_index(&stack->a);
	minValue = find_min(stack->a, 1);
	size = ft_lstsize(stack->a);
	if (min < size / 2)
		while (stack->a->nb != minValue)
			ops(stack, 6, "rra");
	else
		while (stack->a->nb != minValue)
			ops(stack, 3, "ra");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 18:46:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push(int first_a, int last_a, int first_b)
{
	if (first_a > first_b && first_a < last_a)
		return (1);
	else if (first_a > first_b && first_b > last_a)
		return (1);
	else if (first_a < last_a && first_b > last_a)
		return (1);
	return (0);
}

void	algo_pushB(t_stack *stack, t_index chunk)
{
	int	i;
	int	limit;
	int	sizeA;
	int	chunkSize;

	sizeA = ft_lstsize(stack->a);
	chunkSize = 3;
	if (sizeA > 99)
	{
		i = 0;
		while (++i < chunkSize)
		{
			if ((stack->a->index < chunk.begin || stack->a->index > chunk.end)
				&& stack->a->pos < sizeA * i / chunkSize)
				ops(stack, 10, "pb");
			else
				ops(stack, 3, "ra");
		}
	}
	if (stack->a->index < chunk.begin || stack->a->index > chunk.end)
		ops(stack, 10, "pb");
	else
		ops(stack, 3, "ra");
}

void	algo_pushA(t_stack *stack)
{
	while (stack->b)
	{
		if (check_push(stack->a->nb, ft_lstlast(stack->a)->nb, stack->b->nb))
			ops(stack, 9, "pa");
		else
		{
			put_index(stack->a);
			put_index(stack->b);
			make_move(stack, get_shortest(stack));
		}
	}
}

void	algo_rotateA(t_stack *stack)
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
	if (minIndex < size / 2)
		while (stack->a->nb != minValue)
			ops(stack, 6, "rra");
	else
		while (stack->a->nb != minValue)
			ops(stack, 3, "ra");
}

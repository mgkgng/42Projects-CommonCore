/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 18:49:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_swap(t_stack *stack)
{
	while (ft_lstsize(stack->a) > 3)
		ops(stack, 10, "pb");
	if (stack->a->nb > stack->a->next->nb
		&& stack->a->next->nb < ft_lstlast(stack->a)->nb
		&& max_find(stack->a) == stack->a->nb)
		ops(stack, 3, "ra");
	else if ((stack->a->nb > stack->a->next->nb)
		|| (max_find(stack->a) == stack->a->next->nb
			&& first_min_find(stack->a) == stack->a->nb))
		ops(stack, 0, "sa");
	if (first_min_find(stack->a) == stack->a->next->nb)
		ops(stack, 3, "ra");
	else if (first_min_find(stack->a) == ft_lstlast(stack->a)->nb)
		ops(stack, 6, "rra");
}

int	push_swap(t_stack *stack)
{
	t_index	chunk;

	if (ft_lstsize(stack->a) == 1)
		return (0);
	put_index(&stack->a);
	// do we really need it? put_nb(&stack->a);
	chunk = get_chunk(stack->a);
	if (chunk.end - chunk.begin + 1 < 3)
		mini_swap(stack);
	else
		algo_pushB(stack, chunk);
	algo_pushA(stack);
	algo_rotateA(stack);
	free_list(stack);
	return (0);
}

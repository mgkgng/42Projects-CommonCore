/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 00:49:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	that_is_the_place(t_list *a, t_list *b)
{
	t_list	*last;

	if (!a || !b)
		return (0);
	last = ft_lstlast(a);
	if (a->nb > b->nb && a->nb < last->nb)
		return (1);
	else if (a->nb > b->nb && b->nb > last->nb)
		return (1);
	else if (a->nb < last->nb && b->nb > last->nb)
		return (1);
	return (0);
}*/

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

void	rotate_at_the_same_time(t_list **a, t_list **b, t_move **move)
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

void	make_move(t_list **a, t_list **b, t_move *move)
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

void	ft_dirty(t_list *a, t_list *b, t_dirty *dirty)
{
	dirty->size_a = ft_lstsize(a);
	dirty->size_b = ft_lstsize(b);
	dirty->begin_a = a;
	dirty->begin_b = b;
	dirty->min = INT32_MAX;
	dirty->last_a = ft_lstlast(a)->pos;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 16:05:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	that_is_the_place(t_list *lst_a, t_list *lst_b)
{
	t_list	*last_list;

	if (!lst_a || !lst_b)
		return (0);
	last_list = ft_lstlast(lst_a);
	if (lst_a->index > lst_b->index && lst_a->index < last_list->index)
		return (1);
	else if (lst_a->index > lst_b->index && lst_b->index > last_list->index)
		return (1);
	else if (lst_a->index < last_list->index && lst_b->index > last_list->index)
		return (1);
	return (0);
}

int	that_is_the_place2(int lst_a, int last_a, int lst_b)
{
	if (lst_a > lst_b && lst_a < last_a)
		return (1);
	else if (lst_a > lst_b && lst_b > last_a)
		return (1);
	else if (lst_a < last_a && lst_b > last_a)
		return (1);
	return (0);
}

void	rotate_at_the_same_time(t_list **lst_a, t_list **lst_b, t_move **move)
{
	while ((*move)->ra > 0 && (*move)->rb > 0)
	{
		rotate_rotate(lst_a, lst_b);
		(*move)->ra--;
		(*move)->rb--;
	}
	while ((*move)->rra > 0 && (*move)->rrb > 0)
	{
		reverse_rotate_rotate(lst_a, lst_b);
		(*move)->rra--;
		(*move)->rrb--;
	}
}

void	make_move(t_list **lst_a, t_list **lst_b, t_move *move)
{
	rotate_at_the_same_time(lst_a, lst_b, &move);
	while (move->ra > 0)
	{
		rotate_a(lst_a);
		move->ra--;
	}
	while (move->rb > 0)
	{
		rotate_b(lst_b);
		move->rb--;
	}
	while (move->rra > 0)
	{
		reverse_rotate_a(lst_a);
		move->rra--;
	}
	while (move->rrb > 0)
	{
		reverse_rotate_b(lst_b);
		move->rrb--;
	}
	push_a(lst_a, lst_b);
}

void	ft_dirty(t_list *lst_a, t_list *lst_b, t_dirty *dirty)
{
	dirty->size_a = ft_lstsize(lst_a);
	dirty->size_b = ft_lstsize(lst_b);
	dirty->begin_a = lst_a;
	dirty->begin_b = lst_b;
	dirty->min = INT32_MAX;
	dirty->last_a = ft_lstlast(lst_a)->index;
}

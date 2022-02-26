/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 16:05:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	opt_define(t_move **move, t_move **opt, t_dirty *dirty)
{
	if ((*move)->rra)
		(*move)->ra = 0;
	if ((*move)->rrb)
		(*move)->rb = 0;
	dirty->sum = (*move)->ra + (*move)->rb + (*move)->rra + (*move)->rrb;
	if (dirty->sum < dirty->min)
	{
		dirty->min = dirty->sum;
		(*opt)->ra = (*move)->ra;
		(*opt)->rra = (*move)->rra;
		(*opt)->rb = (*move)->rb;
		(*opt)->rrb = (*move)->rrb;
	}
}

void	ft_shit(t_list **lst_a, t_list **lst_b, t_dirty *dirty, t_shit *shit)
{
	*lst_a = dirty->begin_a;
	dirty->last_a = ft_lstlast(*lst_a)->index;
	while (*lst_a)
	{
		if (that_is_the_place2((*lst_a)->index, dirty->last_a, (*lst_b)->index))
			opt_define(&shit->move, &shit->opt, dirty);
		dirty->last_a = (*lst_a)->index;
		*lst_a = (*lst_a)->next;
		if (*lst_a)
		{
			shit->move->ra = (*lst_a)->swap_index;
			if ((*lst_a)->swap_index > dirty->size_a / 2)
				shit->move->rra = dirty->size_a - (*lst_a)->swap_index;
		}
	}
	*lst_b = (*lst_b)->next;
	ft_bzero(shit->move, sizeof(t_move));
	if (*lst_b)
	{
		if ((*lst_b)->swap_index < dirty->size_b / 2)
			shit->move->rb = (*lst_b)->swap_index;
		else
			shit->move->rrb = dirty->size_b - (*lst_b)->swap_index;
	}
}

void	optimal_move(t_list **lst_a, t_list **lst_b)
{
	t_dirty	dirty;
	t_shit	shit;

	if (!*lst_a || !*lst_b)
		return ;
	shit.move = ft_calloc(1, sizeof(t_move));
	shit.opt = malloc(sizeof(t_move));
	ft_dirty(*lst_a, *lst_b, &dirty);
	while (*lst_b)
		ft_shit(lst_a, lst_b, &dirty, &shit);
	*lst_a = dirty.begin_a;
	*lst_b = dirty.begin_b;
	make_move(lst_a, lst_b, shit.opt);
	free(shit.move);
	free(shit.opt);
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

void	get_a_in_order(t_list **lst_a)
{
	int	size;

	if ((*lst_a)->index == 0)
		return ;
	size = ft_lstsize(*lst_a);
	if ((*lst_a)->index < size / 2)
	{
		while ((*lst_a)->index != 0)
			reverse_rotate_a(lst_a);
	}
	else
	{
		while ((*lst_a)->index != 0)
			rotate_a(lst_a);
	}
}

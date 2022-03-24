/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:31:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	tmp_a = (*a)->next;
	(*a)->next = tmp_a->next;
	tmp_a->next = *a;
	*a = tmp_a;
	tmp_b = (*b)->next;
	(*b)->next = tmp_b->next;
	tmp_b->next = *b;
	*b = tmp_b;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp_stack;

	if (!*b)
		return ;
	temp_stack = *b;
	*b = (*b)->next;
	temp_stack->next = *a;
	*a = temp_stack;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp_stack;

	if (!*a)
		return ;
	temp_stack = *a;
	*a = (*a)->next;
	temp_stack->next = *b;
	*b = temp_stack;
}

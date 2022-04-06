/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:31:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*last_stack;
	t_stack	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	last_stack = ft_lstlast(*a);
	tmp = (*a)->next;
	last_stack->next = *a;
	(*a)->next = NULL;
	*a = tmp;
}

void	rb(t_stack **b)
{
	t_stack	*last_stack;
	t_stack	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	last_stack = ft_lstlast(*b);
	tmp = (*b)->next;
	last_stack->next = *b;
	(*b)->next = NULL;
	*b = tmp;
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*last_stack1;
	t_stack	*last_stack2;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstsize(*a) >= 2)
	{
		last_stack1 = ft_lstlast(*a);
		tmp1 = (*a)->next;
		last_stack1->next = *a;
		(*a)->next = NULL;
		*a = tmp1;
	}
	if (ft_lstsize(*b) < 2)
		return ;
	last_stack2 = ft_lstlast(*b);
	tmp2 = (*b)->next;
	last_stack2->next = *b;
	(*b)->next = NULL;
	*b = tmp2;
}

void	rra(t_stack **a)
{
	t_stack	*last_stack;
	t_stack	*before_last_stack;

	if (ft_lstsize(*a) < 2)
		return ;
	last_stack = ft_lstlast(*a);
	before_last_stack = ft_before_last(*a);
	last_stack->next = *a;
	before_last_stack->next = NULL;
	*a = last_stack;
}

void	rrb(t_stack **b)
{
	t_stack	*last_stack;
	t_stack	*before_last_stack;

	if (ft_lstsize(*b) < 2)
		return ;
	last_stack = ft_lstlast(*b);
	before_last_stack = ft_before_last(*b);
	last_stack->next = *b;
	before_last_stack->next = NULL;
	*b = last_stack;
}

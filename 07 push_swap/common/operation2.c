/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:26:02 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **lst_a)
{
	t_stack	*last_stack;
	t_stack	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	last_stack = ft_lstlast(*lst_a);
	tmp = (*lst_a)->next;
	last_stack->next = *lst_a;
	(*lst_a)->next = NULL;
	*lst_a = tmp;
}

void	rb(t_stack **lst_b)
{
	t_stack	*last_stack;
	t_stack	*tmp;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_stack = ft_lstlast(*lst_b);
	tmp = (*lst_b)->next;
	last_stack->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = tmp;
}

void	rr(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*last_stack1;
	t_stack	*last_stack2;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstsize(*lst_a) >= 2)
	{
		last_stack1 = ft_lstlast(*lst_a);
		tmp1 = (*lst_a)->next;
		last_stack1->next = *lst_a;
		(*lst_a)->next = NULL;
		*lst_a = tmp1;
	}
	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_stack2 = ft_lstlast(*lst_b);
	tmp2 = (*lst_b)->next;
	last_stack2->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = tmp2;
}

void	rra(t_stack **lst_a)
{
	t_stack	*last_stack;
	t_stack	*before_last_stack;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	last_stack = ft_lstlast(*lst_a);
	before_last_stack = ft_lst_before_last(*lst_a);
	last_stack->next = *lst_a;
	before_last_stack->next = NULL;
	*lst_a = last_stack;
}

void	rrb(t_stack **lst_b)
{
	t_stack	*last_stack;
	t_stack	*before_last_stack;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_stack = ft_lstlast(*lst_b);
	before_last_stack = ft_lst_before_last(*lst_b);
	last_stack->next = *lst_b;
	before_last_stack->next = NULL;
	*lst_b = last_stack;
}

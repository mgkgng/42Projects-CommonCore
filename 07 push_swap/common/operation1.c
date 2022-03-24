/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:42:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **lst_a)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	tmp = (*lst_a)->next;
	(*lst_a)->next = tmp->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
}

void	sb(t_stack **lst_b)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	tmp = (*lst_b)->next;
	(*lst_b)->next = tmp->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
}

void	ss(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (ft_lstsize(*lst_a) < 2 || ft_lstsize(*lst_b) < 2)
		return ;
	tmp_a = (*lst_a)->next;
	(*lst_a)->next = tmp_a->next;
	tmp_a->next = *lst_a;
	*lst_a = tmp_a;
	tmp_b = (*lst_b)->next;
	(*lst_b)->next = tmp_b->next;
	tmp_b->next = *lst_b;
	*lst_b = tmp_b;
}

void	pa(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp_stack;

	if (!*lst_b)
		return ;
	temp_stack = *lst_b;
	*lst_b = (*lst_b)->next;
	temp_stack->next = *lst_a;
	*lst_a = temp_stack;
}

void	pb(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp_stack;

	if (!*lst_a)
		return ;
	temp_stack = *lst_a;
	*lst_a = (*lst_a)->next;
	temp_stack->next = *lst_b;
	*lst_b = temp_stack;
}

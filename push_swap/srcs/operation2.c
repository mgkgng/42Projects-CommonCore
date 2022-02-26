/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 14:31:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **lst_a)
{
	t_list	*last_list;
	t_list	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	last_list = ft_lstlast(*lst_a);
	tmp = (*lst_a)->next;
	last_list->next = *lst_a;
	(*lst_a)->next = NULL;
	*lst_a = tmp;
}

void	rb(t_list **lst_b)
{
	t_list	*last_list;
	t_list	*tmp;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_list = ft_lstlast(*lst_b);
	tmp = (*lst_b)->next;
	last_list->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = tmp;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_list1;
	t_list	*last_list2;
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(*lst_a) >= 2)
	{
		last_list1 = ft_lstlast(*lst_a);
		tmp1 = (*lst_a)->next;
		last_list1->next = *lst_a;
		(*lst_a)->next = NULL;
		*lst_a = tmp1;
	}
	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_list2 = ft_lstlast(*lst_b);
	tmp2 = (*lst_b)->next;
	last_list2->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = tmp2;
}

void	rra(t_list **lst_a)
{
	t_list	*last_list;
	t_list	*before_last_list;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	last_list = ft_lstlast(*lst_a);
	before_last_list = ft_lst_before_last(*lst_a);
	last_list->next = *lst_a;
	before_last_list->next = NULL;
	*lst_a = last_list;
}

void	rrb(t_list **lst_b)
{
	t_list	*last_list;
	t_list	*before_last_list;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_list = ft_lstlast(*lst_b);
	before_last_list = ft_lst_before_last(*lst_b);
	last_list->next = *lst_b;
	before_last_list->next = NULL;
	*lst_b = last_list;
}

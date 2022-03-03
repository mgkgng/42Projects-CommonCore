/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 14:33:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **lst_a)
{
	t_list	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	tmp = (*lst_a)->next;
	(*lst_a)->next = tmp->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
}

void	sb(t_list **lst_b)
{
	t_list	*tmp;

	if (ft_lstsize(*lst_b) < 2)
		return ;
	tmp = (*lst_b)->next;
	(*lst_b)->next = tmp->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

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

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp_list;

	if (!*lst_b)
		return ;
	temp_list = *lst_b;
	*lst_b = (*lst_b)->next;
	temp_list->next = *lst_a;
	*lst_a = temp_list;
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp_list;

	if (!*lst_a)
		return ;
	temp_list = *lst_a;
	*lst_a = (*lst_a)->next;
	temp_list->next = *lst_b;
	*lst_b = temp_list;
}

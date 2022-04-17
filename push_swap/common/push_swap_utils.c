/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:45:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	first_min_find(t_list *lst)
{
	int		min;
	t_list	*begin;

	begin = lst;
	min = INT32_MAX;
	while (lst)
	{
		if (lst->nb < min)
			min = lst->nb;
		lst = lst->next;
	}
	lst = begin;
	return (min);
}

int	next_min_find(t_list *l, int already)
{
	int		min;
	t_list	*begin;

	begin = l;
	while (l->nb <= already)
	l = l->next;
	min = l->nb;
	while (l)
	{
		if (l->nb < min && l->nb > already)
			min = l->nb;
		l = l->next;
	}
	l = begin;
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 14:20:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *l)
{
	int		min;

	min = l->nb;
	while (l)
	{
		if (l->nb < min)
			min = l->nb;
		l = l->next;
	}
	return (min);
}

/*int	find_next_min(t_list *l, int before)
{
	int		min;
	t_list	*begin;

	begin = l;
	while (l->nb <= before)
		l = l->next;
	min = l->nb;
	while (l)
	{
		if (l->nb < min && l->nb > before)
			min = l->nb;
		l = l->next;
	}
	l = begin;
	return (min);
}*/

int	find_indexZero(t_list *l)
{
	int	i;
	
	i = 0;
	while (l)
	{
		if (!l->index)
			return (i);
		i++;
		l = l->next;
	}
}

t_list	*ft_lst_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
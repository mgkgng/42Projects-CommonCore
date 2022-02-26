/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 16:06:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

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
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	lst = begin;
	return (min);
}

int	next_min_find(t_list *lst, int already)
{
	int		min;
	t_list	*begin;

	begin = lst;
	while (lst->content <= already)
	lst = lst->next;
	min = lst->content;
	while (lst)
	{
		if (lst->content < min && lst->content > already)
			min = lst->content;
		lst = lst->next;
	}
	lst = begin;
	return (min);
}

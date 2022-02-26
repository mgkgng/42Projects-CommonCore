/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 17:12:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_index_put(t_list **lst, int min, int min_index)
{
	t_list	*begin;

	begin = *lst;
	while ((*lst)->content != min && *lst)
		*lst = (*lst)->next;
	(*lst)->index = min_index;
	*lst = begin;
}

void	put_index(t_list **lst)
{
	int	index;
	int	min;
	int	size;

	index = 0;
	size = ft_lstsize(*lst);
	min = first_min_find(*lst);
	min_index_put(lst, min, index++);
	while (index < size)
	{
		min = next_min_find(*lst, min);
		min_index_put(lst, min, index++);
	}
}

void	swap_index(t_list **lst)
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = *lst;
	while (*lst)
	{
		(*lst)->swap_index = i++;
		(*lst) = (*lst)->next;
	}
	*lst = begin;
}

t_list	*new_list(t_list *lst)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	result->content = lst->content;
	result->index = lst->index;
	result->swap_index = lst->swap_index;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

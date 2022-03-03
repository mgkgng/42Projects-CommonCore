/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/10 10:26:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_find(t_list *lst)
{
	int	max;

	max = INT32_MIN;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

void	mini_swap(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a) > 3)
		push_b(lst_a, lst_b);
	if ((*lst_a)->index > (*lst_a)->next->index
		&& (*lst_a)->next->index < ft_lstlast(*lst_a)->index
		&& max_find(*lst_a) == (*lst_a)->content)
		rotate_a(lst_a);
	else if (((*lst_a)->index > (*lst_a)->next->index)
		|| (max_find(*lst_a) == (*lst_a)->next->content
			&& first_min_find(*lst_a) == (*lst_a)->content))
		swap_a(lst_a);
	if (first_min_find(*lst_a) == (*lst_a)->next->content)
		rotate_a(lst_a);
	else if (first_min_find(*lst_a) == ft_lstlast(*lst_a)->content)
		reverse_rotate_a(lst_a);
}

void	push_swap(t_list **lst_a, t_list **lst_b)
{
	t_index	chunk;

	if (ft_lstsize(*lst_a) == 1)
		return ;
	swap_index(lst_a);
	put_index(lst_a);
	chunk = get_the_biggest_chunk(*lst_a);
	chunk.size = chunk.end - chunk.start + 1;
	if (chunk.size < 3)
		mini_swap(lst_a, lst_b);
	else
		push_everything_in_b(lst_a, lst_b, chunk);
	push_everything_back_in_a(lst_a, lst_b);
	get_a_in_order(lst_a);
}

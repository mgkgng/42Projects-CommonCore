/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 01:47:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_find(t_stack *lst)
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

void	mini_swap(t_stack **lst_a, t_stack **lst_b)
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

int	push_swap(t_stack **a, t_stack **b)
{
	t_index	chunk;

	if (ft_lstsize(*a) == 1)
		return (0);
	swap_index(a);
	put_index(a);
	chunk = get_the_biggest_chunk(*a);
	chunk.size = chunk.end - chunk.start + 1;
	if (chunk.size < 3)
		mini_swap(a, b);
	else
		push_everything_in_b(a, b, chunk);
	push_everything_back_in_a(a, b);
	get_a_in_order(a);
	free_stack(*a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:32:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last_stack1;
	t_stack	*last_stack2;
	t_stack	*before_last_stack1;
	t_stack	*before_last_stack2;

	if (ft_lstsize(*a) >= 2)
	{
		last_stack1 = ft_lstlast(*a);
		before_last_stack1 = ft_before_last(*a);
		last_stack1->next = *a;
		before_last_stack1->next = NULL;
		*a = last_stack1;
	}
	if (ft_lstsize(*b) < 2)
		return ;
	last_stack2 = ft_lstlast(*b);
	before_last_stack2 = ft_before_last(*b);
	last_stack2->next = *b;
	before_last_stack2->next = NULL;
	*b = last_stack2;
}

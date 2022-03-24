/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:18:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_list1;
	t_list	*last_list2;
	t_list	*before_last_list1;
	t_list	*before_last_list2;

	if (ft_lstsize(*lst_a) >= 2)
	{
		last_list1 = ft_lstlast(*lst_a);
		before_last_list1 = ft_lst_before_last(*lst_a);
		last_list1->next = *lst_a;
		before_last_list1->next = NULL;
		*lst_a = last_list1;
	}
	if (ft_lstsize(*lst_b) < 2)
		return ;
	last_list2 = ft_lstlast(*lst_b);
	before_last_list2 = ft_lst_before_last(*lst_b);
	last_list2->next = *lst_b;
	before_last_list2->next = NULL;
	*lst_b = last_list2;
}

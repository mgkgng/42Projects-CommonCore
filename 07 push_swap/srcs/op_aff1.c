/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:18:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:17:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	sa(a);
	ft_putstr("sa\n");
}

void	swap_b(t_list **b)
{
	sb(b);
	ft_putstr("sb\n");
}

void	swap_swap(t_list **a, t_list **b)
{
	ss(a, b);
	ft_putstr("ss\n");
}

void	push_a(t_list **a, t_list **b)
{
	pa(a, b);
	ft_putstr("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	pb(a, b);
	ft_putstr("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:18:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 14:14:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	sa(a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **b)
{
	sb(b);
	ft_putstr("sb\n");
}

void	swap_swap(t_stack **a, t_stack **b)
{
	ss(a, b);
	ft_putstr("ss\n");
}

void	push_a(t_stack **a, t_stack **b)
{
	pa(a, b);
	ft_putstr("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	ft_putstr("pb\n");
}

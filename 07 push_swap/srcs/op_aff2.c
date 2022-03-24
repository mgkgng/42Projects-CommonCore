/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:19:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:17:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	ra(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_list **b)
{
	rb(b);
	ft_putstr("rb\n");
}

void	rotate_rotate(t_list **a, t_list **b)
{
	rr(a, b);
	ft_putstr("rr\n");
}

void	reverse_rotate_a(t_list **a)
{
	rra(a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	rrb(b);
	ft_putstr("rrb\n");
}

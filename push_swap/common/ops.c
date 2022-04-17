/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:59:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **l)
{
	t_list	*tmp;

	if (ft_lstsize(*l) < 2)
		return ;
	tmp = (*l)->next;
	(*l)->next = tmp->next;
	tmp->next = *l;
	*l = tmp;
}

static void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

static void	rotate(t_list **l)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*l) < 2)
		return ;
	last = ft_lstlast(*l);
	tmp = (*l)->next;
	last->next = *l;
	(*l)->next = NULL;
	*l = tmp;
}

// maybe there could be a way to unify rotate and reverse_rotate by using a flag
static void	reverse_rotate(t_list **l)
{
	t_list	*last;
	t_list	*second_last;

	if (ft_lstsize(*l) < 2)
		return ;
	last = ft_lstlast(*l);
	second_last = ft_before_last(*l);
	last->next = *l;
	second_last->next = NULL;
	*l = last;
}

// should find an elegant and simple way to distribute the execution of operations
void	ops(t_stack *stack, char *s, int print)
{
	if (!ft_strcmp(s, "sa"))
		swap(&stack->a);
	if (!ft_strcmp(s, "sb"))
		swap(&stack->b);
	if (!ft_strcmp(s, "pa"))
		push(b, a);
	if (!ft_strcmp(s, "pb"))
		push(a, b);
	if (!ft_strcmp(s, "ra"))
		rotate(a);
	if (!ft_strcmp(s, "rb"))
		rotate(b);
	if (!ft_strcmp(s, "rra"))
		reverse_rotate(a);
	if (!ft_strcmp(s, "rrb"))
		reverse_rotate(b);
	if (!ft_strcmp(s, "ss"))
	{
		swap(a);
		swap(b);
	}
	if (!ft_strcmp(s, "ss"))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strcmp(s, "ss"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	if (print)
		ft_putstr(s);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 22:21:45 by min-kang         ###   ########.fr       */
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

//* 0 -> sa
//* 1 - > sb
//* 2 -> ra
//* 3 -> rb
//* 4 -> rra
//* 5 -> rrb
//* 6 -> 
//*
//*
//*
//*
//*
//*
// should find an elegant and simple way to distribute the execution of operations
void	ops(t_stack *stack, int op, char *s)
{
	t_list	*obj;

	if (op < 6 && !(op % 2))
		obj = &stack->a;
	else if (op < 6 && op % 2)
		obj = &stack->b;
	if (op / 2 == 0)
		swap(obj);
	if (op / 2 == 1)
		rotate(obj);
	if (op / 2 == 2)
		reverse_rotate(obj);
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
	if (s)
		ft_putstr(s);
}
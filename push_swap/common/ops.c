/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 00:14:26 by min-kang         ###   ########.fr       */
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

static void	rotate(t_list **l, int reverse)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*l) < 2)
		return ;
	last = ft_lstlast(*l);
	last->next = *l;
	if (!reverse)
	{
		tmp = (*l)->next;
		(*l)->next = NULL;
		*l = tmp;
	}
	else
	{
		tmp = ft_before_last(*l);
		tmp->next = NULL;
		*l = last;
	}
}

//* 0 -> sa
//* 1 - > sb
//* 2 -> ss
//* 3 -> ra
//* 4 -> rb
//* 5 -> rr
//* 6 -> rra
//* 7 -> rrb
//* 8 -> rrr
//* 9 -> pa
//* 10 -> pb

void	ops(t_stack *stack, int op, char *s)
{
	t_list	*obj;

	if (s)
		ft_putstr(s);
	if (!(op % 3))
		obj = &stack->a;
	else
		obj = &stack->b;
	if (!(op / 3))
		swap(obj);
	else if (op / 3 == 1)
		rotate(obj, 0);
	else if (op / 3 == 2)
		rotate(obj, 1);
	if (op < 9 && op % 3 == 2)
		ops(stack, op - 2, NULL);
	if (op == 10)
		push(&stack->b, &stack->a);
	else if (op == 11)
		push(&stack->a, &stack->b);
}
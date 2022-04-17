/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:14:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:52:11 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operation(t_stack stack, char *to_do)
{
	if (!ft_strcmp(to_do, "sa"))
		ops(stack.a, "sa");
	else if (!ft_strcmp(to_do, "sb"))
		sb(b);
	else if (!ft_strcmp(to_do, "ss"))
		ss(a, b);
	else if (!ft_strcmp(to_do, "pa"))
		pa(a, b);
	else if (!ft_strcmp(to_do, "pb"))
		pb(a, b);
	else if (!ft_strcmp(to_do, "ra"))
		ra(a);
	else if (!ft_strcmp(to_do, "rb"))
		rb(b);
	else if (!ft_strcmp(to_do, "rr"))
		rr(a, b);
	else if (!ft_strcmp(to_do, "rra"))
		rra(a);
	else if (!ft_strcmp(to_do, "rrb"))
		rrb(b);
	else if (!ft_strcmp(to_do, "rrr"))
		rrr(a, b);
	else
		exit_error();
}

void	execute(t_stack **a, t_stack **b, char *s)
{
	char	**to_do;
	int		i;

	if (!s)
		check_free_exit(*a, *b);
	to_do = ft_split(s, '\n');
	i = -1;
	while (to_do[++i])
		operation(a, b, to_do[i]);
	check_free_exit(*a, *b);
}

int	checker(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	if (b)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:14:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 19:15:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	operation(t_list **lst_a, t_list **lst_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		sa(lst_a);
	else if (!ft_strcmp(instruction, "sb"))
		sb(lst_b);
	else if (!ft_strcmp(instruction, "ss"))
		ss(lst_a, lst_b);
	else if (!ft_strcmp(instruction, "pa"))
		pa(lst_a, lst_b);
	else if (!ft_strcmp(instruction, "pb"))
		pb(lst_a, lst_b);
	else if (!ft_strcmp(instruction, "ra"))
		ra(lst_a);
	else if (!ft_strcmp(instruction, "rb"))
		rb(lst_b);
	else if (!ft_strcmp(instruction, "rr"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(instruction, "rra"))
		rra(lst_a);
	else if (!ft_strcmp(instruction, "rrb"))
		rrb(lst_b);
	else if (!ft_strcmp(instruction, "rrr"))
		rrr(lst_a, lst_b);
	else
		exit_error();
}

void	execute(t_list **lst_a, t_list **lst_b, char *s)
{
	char	**instruction;
	int		i;

	if (!s)
		check_free_exit(*lst_a, *lst_b);
	instruction = ft_split(s, '\n');
	i = -1;
	while (instruction[++i])
		operation(lst_a, lst_b, instruction[i]);
	check_free_exit(*lst_a, *lst_b);
}

int	checker(t_list *lst_a, t_list *lst_b)
{
	while (lst_a->next)
	{
		if (lst_a->content > lst_a->next->content)
			return (0);
		lst_a = lst_a->next;
	}
	if (lst_b)
		return (0);
	return (1);
}

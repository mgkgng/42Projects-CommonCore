/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 14:28:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	there_is_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]))
			return (1);
	return (0);
}

int	digit_check(char *s)
{
	int	i;

	if (!there_is_digit(s))
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (0);
	return (1);
}

t_list	*parsing_list(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*begin;

	lst = malloc(sizeof(t_list));
	begin = lst;
	i = 0;
	while (++i < argc)
	{
		lst->content = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			lst->next = malloc(sizeof(t_list));
			lst = lst->next;
		}
		else
			lst->next = NULL;
	}
	return (begin);
}

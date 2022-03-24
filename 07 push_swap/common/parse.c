/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:37:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_stack	*parse1(char **argv)
{
	
}

static t_stack	*parse2(int argc, char **argv)
{
	int		i;
	t_stack	*st;
	t_stack	*begin;

	st = malloc(sizeof(t_stack));
	begin = st;
	i = 0;
	while (++i < argc)
	{
		st->content = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			st->next = malloc(sizeof(t_stack));
			st = st->next;
		}
		else
			st->next = NULL;
	}
	return (begin);
}

t_stack	*parse(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (NULL);
	if (argc == 2)
		return (parse1(argv));
	return (parse2(argc, argv));
}

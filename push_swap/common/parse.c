/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 18:22:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	check_error(char *s)
{
	int	i;

	if (!ft_strlen(s))
		return (0);
	i = -1;
	while (s[++i])
	{
		if (!ft_digit(s[i]))
		{
			if (!i && (s[i] == '-' || s[i] == '+'))
			{
				if (!s[i + 1])
					return (0);
				continue;
			}
			else
				return (0);
		}
	}
}

static t_list	*do_parse(char **argv, int start)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	while (argv[start])
	{
		if (!check_error(argv[start]))
		{
			free_list(res);
			error_exit();
		}
		ft_lstadd_back(&res, ft_lstnew(ft_atoi(argv[start++])));
	}
	return (res);
}

t_list	*parse(int argc, char **argv)
{
	if (argc == 2)
		return(do_parse(ft_split(argv[1], ' '), 0));
	return (do_parse(argv, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:49:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*parse1(char **argv)
{
	
}

static t_list	*parse2(int argc, char **argv)
{
	int		i;
	t_list	*res;

	res = malloc(sizeof(t_list));
	i = 0;
	while (++i < argc)
		ft_lstadd_back(&res, ft_lstnew(ft_atoi(argv[i])));
	return (res);
}

t_list	*parse(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (NULL);
	if (argc == 2)
		return (parse1(argv));
	return (parse2(argc, argv));
}

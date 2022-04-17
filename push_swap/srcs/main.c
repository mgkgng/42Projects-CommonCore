/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:46:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = parse(argc, argv);
	if (!a)
		return (print_error());
	b = NULL;
	return (push_swap(&a, &b));
}

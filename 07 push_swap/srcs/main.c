/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/10 10:25:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	check_error(argc, argv);
	stack_a = parsing_list(argc, argv);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}

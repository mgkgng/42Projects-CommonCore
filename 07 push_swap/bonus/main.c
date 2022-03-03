/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:16:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/11 17:25:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	exit_ok(void)
{
	ft_putstr("OK\n");
	exit(EXIT_SUCCESS);
}

void	exit_ko(void)
{
	ft_putstr_fd("KO\n", 2);
	exit(EXIT_FAILURE);
}

void	check_free_exit(t_list *lst_a, t_list *lst_b)
{
	if (checker(lst_a, lst_b))
	{
		free_stack(lst_a);
		exit_ok();
	}
	free(lst_a);
	free(lst_b);
	exit_ko();
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	buf[BUFFER_SIZE];
	int		ret;
	char	*r_data;

	if (argc < 2)
		return (0);
	check_error(argc, argv);
	stack_a = parsing_list(argc, argv);
	stack_b = NULL;
	r_data = NULL;
	ret = read(0, &buf, BUFFER_SIZE);
	if (ret < 0)
		execute(&stack_a, &stack_b, r_data);
	while (ret)
	{
		buf[ret] = '\0';
		r_data = ft_strjoin_gnl(r_data, buf);
		ret = read(0, &buf, BUFFER_SIZE);
	}
	execute(&stack_a, &stack_b, r_data);
}

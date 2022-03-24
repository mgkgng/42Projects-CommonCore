/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:16:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 14:08:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	check_free_exit(t_stack *a, t_stack *b)
{
	if (checker(a, b))
	{
		free_stack(a);
		exit_ok();
	}
	free(a);
	free(b);
	exit_ko();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	buf[BUFFER_SIZE];
	int		ret;
	char	*r_data;

	if (argc < 2)
		return (0);
	check_error(argc, argv);
	a = parse(argc, argv);
	b = NULL;
	r_data = NULL;
	ret = read(0, &buf, BUFFER_SIZE);
	if (ret < 0)
		execute(&a, &b, r_data);
	while (ret)
	{
		buf[ret] = '\0';
		r_data = ft_strjoin_gnl(r_data, buf);
		ret = read(0, &buf, BUFFER_SIZE);
	}
	execute(&a, &b, r_data);
}

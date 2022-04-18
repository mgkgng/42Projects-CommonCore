/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:16:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 14:42:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
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

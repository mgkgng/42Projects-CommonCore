/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remylachau <remylachau@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:02:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 13:22:35 by remylachau       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	size_count(char **s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
		count++;
	return (count);
}

t_3d	*get_3d(char ***col, int len_x, int len_y)
{
	t_3d	*res;
	int		i;
	int		j;
	int		x;

	res = ft_calloc(len_x * len_y, sizeof(t_3d));
	i = -1;
	a = 0;
	while (++i < len_y)
	{
		j = -1;
		while (++j < len_x)
		{
			res[x].x = (float) j;
			res[x].y = (float) i;
			res[x].z = (float) col[i][j];
			//res[x++].h = data.mat_2d[(int) i][(int) j];
		}
	}
	return (result);
}

char	*get_file(int fd)
{
	char	*line;
	char	*res;

	line = get_next_line(fd);
	while (line)
	{
		res = ft_strjoin_gnl(res, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (res);
}

t_data	get_data(char *r)
{
	t_data	res;
	int		i;
	int		j;
	char	**line;
	char	***col;

	line = ft_split(gnl_data, '\n');
	col = malloc(sizeof(char **) * size_count(line));
	i = -1;
	while (line[++i])
		col[i] = ft_split(line[i], ' ');
	res.n_line = size_count(line);
	res.len_line = size_count(col[0]);
	res.size = res.n_line * res.len_line;
	res.mat_3d = get_3d(col);
	free(line);
	free(col);
	return (res);
}

t_data	parse(int fd)
{
	char	*r;
	t_data	res;
	int		i;

	r = get_file(fd);
	res = get_data(gnl_data_line, gnl_data_colonne);
	res.max = max_find(result);
	res.min = min_find(result);

	return (res);
}

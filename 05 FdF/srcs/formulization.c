/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:02:10 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/19 17:45:59 by min-kang         ###   ########.fr       */
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

t_3d	*create_3d_matrice(t_map data)
{
	t_3d	*result;
	float	i;
	float	j;
	int		a;

	result = malloc(data.size * sizeof(t_3d));
	i = -1;
	a = 0;
	while (++i < data.n_line)
	{
		j = -1;
		while (++j < data.len_line)
		{
			result[a].x = j;
			result[a].y = i;
			result[a].z = (float) data.mat_2d[(int) i][(int) j];
			result[a++].h = data.mat_2d[(int) i][(int) j];
		}
	}
	return (result);
}

char	*from_gnl(int fd)
{
	char	*r_data;
	char	*result;

	result = NULL;
	r_data = get_next_line(fd);
	while (r_data)
	{
		result = ft_strjoin_gnl(result, r_data);
		r_data = get_next_line(fd);
	}
	free(r_data);
	return (result);
}

t_map	parsing(char **gnl_data_line, char ***gnl_data_colonne)
{
	t_map	result;
	int		i;
	int		j;

	result.n_line = size_count(gnl_data_line);
	result.len_line = size_count(gnl_data_colonne[0]);
	result.mat_2d = malloc(result.n_line * sizeof(int *));
	result.size = result.n_line * result.len_line;
	i = -1;
	while (++i < result.n_line)
	{
		j = -1;
		result.mat_2d[i] = malloc(result.len_line * sizeof(int));
		while (++j < result.len_line)
		{
			if (!gnl_data_colonne[i][j])
				while (j < result.len_line)
					result.mat_2d[i][j++] = 0;
			else
				result.mat_2d[i][j] = ft_atoi(gnl_data_colonne[i][j]);
		}
	}
	result.mat_3d = create_3d_matrice(result);
	return (result);
}

t_map	data_2d_matrice(int fd)
{
	char	*gnl_data;
	t_map	result;
	int		i;
	char	**gnl_data_line;
	char	***gnl_data_colonne;

	gnl_data = from_gnl(fd);
	gnl_data_line = ft_split(gnl_data, '\n');
	gnl_data_colonne = malloc(sizeof(char **) * size_count(gnl_data_line));
	i = -1;
	while (gnl_data_line[++i])
		gnl_data_colonne[i] = ft_split(gnl_data_line[i], ' ');
	result = parsing(gnl_data_line, gnl_data_colonne);
	result.max = max_find(result);
	result.min = min_find(result);
	free(gnl_data_line);
	free(gnl_data_colonne);
	return (result);
}

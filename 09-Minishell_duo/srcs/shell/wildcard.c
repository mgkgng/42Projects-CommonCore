/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:30:26 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/23 17:16:49 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

static struct dirent	*ft_readdir(DIR *dir, struct dirent **entries)
{
	*entries = readdir(dir);
	return (*entries);
}

static int	dirlen(char *dirname)
{	
	DIR				*dir;
	struct dirent	*entries;
	int				i;

	i = 0;
	dir = opendir(dirname);
	while (ft_readdir(dir, &entries))
		if (entries->d_name[0] != '.')
			i++;
	closedir(dir);
	return (i);
}

char	**wildcard(char *dirname)
{
	DIR				*dir;
	struct dirent	*entries;
	char			**strs;
	int				i;

	i = 0;
	dir = opendir(dirname);
	strs = malloc(sizeof(char *) * (dirlen(dirname) + 1));
	while (ft_readdir(dir, &entries))
		if (entries->d_name[0] != '.')
			strs[i++] = ft_strdup(entries->d_name);
	strs[i] = 0;
	closedir(dir);
	i = -1;
	return (strs);
}

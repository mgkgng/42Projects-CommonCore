/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:50:34 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/24 15:39:24 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_init_data(void *data)
{
	(void) *data;
}

void	list_free_data(void *data)
{
	free(data);
}

int	list_data_eq(void *data1, void *data2)
{
	if (*(int *)data1 == *(int *)data2)
		return (1);
	else
		return (0);
}

int	list_dtoi(void *data)
{
	return (*(int *)data);
}

int	list_get_int_index(t_list *plist, int value)
{
	int			i;

	i = -1;
	while (plist && ++i >= 0 && list_get_int(plist) != value)
		plist = plist->next;
	return (i);
}

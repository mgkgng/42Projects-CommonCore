/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:26:31 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/24 15:05:53 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

int	list_length(t_list *plist)
{
	int			i;

	i = 0;
	while (plist)
	{
		plist = plist->next;
		i++;
	}
	return (i);
}

int	list_max_value(t_list *plist)
{
	int			max;

	max = list_get_int(plist);
	while (plist)
	{
		if (max < list_get_int(plist))
			max = list_get_int(plist);
		plist = plist->next;
	}
	return (max);
}

int	list_min_value(t_list *plist)
{
	int			min;

	min = list_get_int(plist);
	while (plist)
	{
		if (min > list_get_int(plist))
			min = list_get_int(plist);
		plist = plist->next;
	}
	return (min);
}

t_info	list_int_info(t_list *plist)
{
	t_info		info;

	if (plist != NULL)
	{
		info.max = list_max_value(plist);
		info.min = list_min_value(plist);
		info.size = list_length(plist);
	}
	else
	{
		info.max = 0;
		info.min = 0;
		info.size = 0;
	}
	return (info);
}

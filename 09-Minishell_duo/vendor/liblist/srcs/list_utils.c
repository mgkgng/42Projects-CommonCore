/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:35:47 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/24 15:06:01 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

int	list_push_uniq(t_list **plist, void *data)
{
	t_list		*list;
	t_list		*newlist;
	int			i;

	i = 0;
	if (*plist)
	{
		list = (*plist);
		while (list && list->next && ++i && !list_data_eq(data, list->data))
			list = list->next;
		if (list && list_data_eq(data, list->data))
			return (0);
		newlist = list_new(data);
		list->next = newlist;
	}
	else
	{
		newlist = list_new(data);
		*plist = newlist;
	}
	if (!newlist)
		return (0);
	return (i + 2);
}

int	list_get_int(t_list *list)
{
	return (list_dtoi(list->data));
}

char	*list_get_str(t_list *list)
{
	return ((char *)list->data);
}

t_list	*list_last(t_list **plist)
{
	int			i;

	i = 0;
	while (*plist && (*plist)->next)
		plist = &((*plist)->next);
	return (*plist);
}

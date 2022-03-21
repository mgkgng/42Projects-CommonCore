/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:47:25 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/24 15:05:48 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_list	*list_new(void *data)
{
	t_list		*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	list_init_data(data);
	return (list);
}

/* prepend */
int	list_unshift(t_list **plist, void *data)
{
	t_list		*newlist;

	newlist = list_new(data);
	if (!newlist)
		return (0);
	newlist->next = *plist;
	*plist = newlist;
	return (1);
}

/* append */
int	list_push(t_list **plist, void *data)
{
	t_list		*list;
	t_list		*newlist;
	int			i;

	i = 0;
	if (*plist)
	{
		list = (*plist);
		while (list && list->next && ++i)
			list = list->next;
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

t_list	*list_splice(t_list **plist, int start, int deleteCount, t_list **slist)
{
	t_list		*newlist;

	newlist = list_slice(plist, start, deleteCount);
	while (*plist && start-- > 0)
		plist = &((*plist)->next);
	while (start <= 0 && *slist)
	{
		list_unshift(plist, list_shift(slist));
		plist = &((*plist)->next);
	}
	return (newlist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:53:46 by gphilipp          #+#    #+#             */
/*   Updated: 2022/01/14 15:36:54 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H

# include <stdlib.h>

typedef struct s_list	t_list;
struct s_list
{
	t_list		*next;
	void		*data;
};

typedef struct s_list_info
{
	int			max;
	int			min;
	int			size;
}	t_info;

/* list_create */
t_list		*list_new(void *data);
int			list_unshift(t_list **plist, void *data);
int			list_push(t_list **plist, void *data);
t_list		*list_splice(t_list **plist, int start, int deleteCount,
				t_list **slist);
/* list_info */
int			list_length(t_list *plist);
int			list_max_value(t_list *plist);
int			list_min_value(t_list *plist);
t_info		list_int_info(t_list *plist);
/* list_shift */
void		*list_shift(t_list **plist);
void		*list_pop(t_list **plist);
t_list		*list_slice(t_list **plist, int start, int deleteCount);
t_list		*list_map(t_list **plist, int (*map)(t_list **item, int index,
					t_list **plist));
int			list_clear(t_list **plist, void (*free_data)(void *data));
/* list_utils */
int			list_push_uniq(t_list **plist, void *data);
int			list_get_int(t_list *list);
char		*list_get_str(t_list *list);
t_list		*list_last(t_list **plist);

/* custom function */
void		list_init_data(void *data);
void		list_free_data(void *data);
int			list_data_eq(void *data1, void *data2);
int			list_dtoi(void *data);

#endif

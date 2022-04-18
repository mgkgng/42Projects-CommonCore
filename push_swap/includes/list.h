/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:48:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 18:23:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list {
	int				nb;
	int				pos;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}	t_stack;


#endif
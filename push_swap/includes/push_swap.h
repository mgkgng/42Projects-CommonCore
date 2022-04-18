/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 18:35:48 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "list.h"

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	sum;
}	t_move;

typedef struct s_value {
	int	value;
	int	index;
}	t_value;

typedef struct s_index {
	int	begin;
	int	end;
	int	size;
}	t_index;

void	ops(t_stack *stack, int op, char *s);

/* utils */
void	put_index(t_list **lst);
t_index	get_chunk(t_list *lst);


#endif

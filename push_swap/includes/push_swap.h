/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 12:49:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

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

#endif

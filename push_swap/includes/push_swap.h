/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 01:31:36 by min-kang         ###   ########.fr       */
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

typedef struct s_dirty {
	int		size_a;
	int		size_b;
	t_list	*begin_a;
	t_list	*begin_b;
	int		last_a;
	int		sum;
	int		min;
}	t_dirty;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	sum;
}	t_move;

typedef struct s_shit {
	t_move	*move;
	t_move	*opt;
}	t_shit;

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

/* error */
int		check_error(int argc, char **argv);
int		print_error(void);


#endif

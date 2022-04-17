/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 22:14:47 by min-kang         ###   ########.fr       */
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

void	ops(t_stack *stack, char *s, int print);

t_list	*parsing_list(int argc, char **argv);
t_list	*ft_lst_before_last(t_list *lst);
int		push_swap(t_list **list_a, t_list **list_b);
void	swap_index(t_list **lst);
void	free_list(t_list *lst);
void	put_index(t_list **lst);
t_list	*new_list(t_list *lst);
t_index	get_the_biggest_chunk(t_list *lst);
int		chunk_limit(t_list *lst, t_index chunk, int i);
void	push_or_rotate(t_list **lst_a, t_list **lst_b, t_index chunk, int i);
void	push_everything_in_b(t_list **lst_a, t_list **lst_b, t_index chunk);
int		that_is_the_place(t_list *lst_a, t_list *lst_b);
int		that_is_the_place2(int lst_a, int last_a, int lst_b);
void	rotate_at_the_same_time(t_list **lst_a, t_list **lst_b, t_move **move);
void	make_move(t_list **lst_a, t_list **lst_b, t_move *move);
void	ft_dirty(t_list *lst_a, t_list *lst_b, t_dirty *dirty);
void	opt_define(t_move **move, t_move **opt, t_dirty *dirty);
void	ft_shit(t_list **lst_a, t_list **lst_b, t_dirty *dirty, t_shit *shit);
void	optimal_move(t_list **lst_a, t_list **lst_b);
void	push_everything_back_in_a(t_list **lst_a, t_list **lst_b);
void	get_a_in_order(t_list **lst_a);
void	min_index_put(t_list **lst, int min, int min_index);
void	put_index(t_list **lst);
void	swap_index(t_list **lst);
t_list	*new_list(t_list *lst);
int		first_min_find(t_list *lst);
int		next_min_find(t_list *lst, int already);
int		digit_check(char *s);
int		ft_strcmp(char *s1, char *s2);
void	exit_error(void);

/* error */
int		check_error(int argc, char **argv);
int		print_error(void);


#endif

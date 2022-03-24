/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:15:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				swap_index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_dirty {
	int		size_a;
	int		size_b;
	t_stack	*begin_a;
	t_stack	*begin_b;
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
	int	start;
	int	end;
	int	size;
	int	entire;
}	t_index;

t_stack	*parsing_list(int argc, char **argv);
t_stack	*ft_lst_before_last(t_stack *lst);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_swap(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_rotate(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_rotate(t_stack **a, t_stack **b);
void	ft_putstr(char *s);
int		push_swap(t_stack **stack_a, t_stack **stack_b);
void	swap_index(t_stack **lst);
void	free_stack(t_stack *lst);
void	put_index(t_stack **lst);
t_stack	*new_list(t_stack *lst);
t_index	get_the_biggest_chunk(t_stack *lst);
int		chunk_limit(t_stack *lst, t_index chunk, int i);
void	push_or_rotate(t_stack **lst_a, t_stack **lst_b, t_index chunk, int i);
void	push_everything_in_b(t_stack **lst_a, t_stack **lst_b, t_index chunk);
int		that_is_the_place(t_stack *lst_a, t_stack *lst_b);
int		that_is_the_place2(int lst_a, int last_a, int lst_b);
void	rotate_at_the_same_time(t_stack **lst_a, t_stack **lst_b, t_move **move);
void	make_move(t_stack **lst_a, t_stack **lst_b, t_move *move);
void	ft_dirty(t_stack *lst_a, t_stack *lst_b, t_dirty *dirty);
void	opt_define(t_move **move, t_move **opt, t_dirty *dirty);
void	ft_shit(t_stack **lst_a, t_stack **lst_b, t_dirty *dirty, t_shit *shit);
void	optimal_move(t_stack **lst_a, t_stack **lst_b);
void	push_everything_back_in_a(t_stack **lst_a, t_stack **lst_b);
void	get_a_in_order(t_stack **lst_a);
void	min_index_put(t_stack **lst, int min, int min_index);
void	put_index(t_stack **lst);
void	swap_index(t_stack **lst);
t_stack	*new_list(t_stack *lst);
int		first_min_find(t_stack *lst);
int		next_min_find(t_stack *lst, int already);
int		digit_check(char *s);
int		ft_strcmp(char *s1, char *s2);
void	exit_error(void);
void	sa(t_stack **lst_a);
void	sb(t_stack **lst_b);
void	ss(t_stack **lst_a, t_stack **lst_b);
void	pa(t_stack **lst_a, t_stack **lst_b);
void	pb(t_stack **lst_a, t_stack **lst_b);
void	ra(t_stack **lst_a);
void	rb(t_stack **lst_b);
void	rr(t_stack **lst_a, t_stack **lst_b);
void	rra(t_stack **lst_a);
void	rrb(t_stack **lst_b);
void	rrr(t_stack **lst_a, t_stack **lst_b);

/* error */
int		check_error(int argc, char **argv);
int		print_error(void);


#endif

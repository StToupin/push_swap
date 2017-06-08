/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:11:51 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 14:12:05 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "circular_linked_list.h"

typedef enum	e_op
{
	O_SA, O_SB, O_SS, O_PA, O_PB, O_RA, O_RB, O_RR, O_RRA, O_RRB, O_RRR, O_UNK
}				t_op;

typedef struct	s_two_stacks
{
	t_cll		*a;
	t_cll		*b;
	t_cll		*op;
}				t_two_stacks;

typedef struct	s_op_assoc
{
	t_op	op;
	char	*name;
	void	(*f)(t_two_stacks *stacks);
	void	(*rev_f)(t_two_stacks *stacks);
}				t_op_assoc;

/*
** From two_stacks.c
*/

void			two_stacks_free(t_allocated **a_list, t_two_stacks **stacks);
t_two_stacks	*two_stacks_create(t_allocated **a_list);
t_two_stacks	*two_stacks_from_strings(t_allocated **a_list, int n, char **s);
void			two_stacks_print(t_two_stacks *stacks, int fd);
int				two_stacks_is_sorted(t_two_stacks *stacks);

/*
** From two_stacks_op_s.c
*/

void			op_sa(t_two_stacks *stacks);
void			op_sb(t_two_stacks *stacks);
void			op_ss(t_two_stacks *stacks);

/*
** From two_stacks_op_p.c
*/

void			op_pa(t_two_stacks *stacks);
void			op_pb(t_two_stacks *stacks);

/*
** From two_stacks_op_r.c
*/

void			op_ra(t_two_stacks *stacks);
void			op_rb(t_two_stacks *stacks);
void			op_rr(t_two_stacks *stacks);

/*
** From two_stacks_op_rr.c
*/

void			op_rra(t_two_stacks *stacks);
void			op_rrb(t_two_stacks *stacks);
void			op_rrr(t_two_stacks *stacks);

/*
** From two_stacks_do_op.c
*/

t_op_assoc		get_op_assoc(int i);
int				stacks_do_op_assoc(t_allocated **a_list, t_two_stacks *stacks,
														t_op_assoc *op_assoc);
int				stacks_do_op(t_allocated **a_list, t_two_stacks *stacks,
																	t_op op);

/*
** From print_solution.c
*/

void			print_solution(t_two_stacks	*stacks, int fd);

/*
** From algo.c
*/

typedef struct	s_route
{
	int	a;
	int	b;
	int len;
}				t_route;

typedef struct	s_index_value
{
	int	index;
	int	value;
}				t_index_value;

t_route			find_best_route(t_two_stacks *stacks, int i_a, int val_a);

/*
** From algo2.c
*/

void			solve_big(t_allocated **a_list, t_two_stacks *stacks);

#endif

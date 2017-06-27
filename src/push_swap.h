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
# include "my_malloc.h"

typedef enum	e_op
{
	O_SA, O_SB, O_SS, O_PA, O_PB, O_RA, O_RB, O_RR, O_RRA, O_RRB, O_RRR, O_UNK
}				t_op;

typedef struct	s_two_stacks
{
	t_cll		*a;
	t_cll		*b;
	t_cll		*op;
	t_allocated	*a_list;
}				t_two_stacks;

typedef struct	s_op_assoc
{
	char	*name;
	t_op	op;
	int		(*f)(t_two_stacks *stacks);
	t_op	rev_op;
	int		(*rev_f)(t_two_stacks *stacks);
}				t_op_assoc;

/*
** From two_stacks.c
*/

void			two_stacks_free(t_two_stacks *stacks, int verbose);
void			two_stacks_create(t_two_stacks *stacks, int verbose);
int				two_stacks_from_strings(t_two_stacks *stacks, int n, char **s,
																int verbose);
int				two_stacks_is_sorted(t_two_stacks *stacks);

/*
** From two_stacks_op_s.c
*/

int				op_sa(t_two_stacks *stacks);
int				op_sb(t_two_stacks *stacks);
int				op_ss(t_two_stacks *stacks);

/*
** From two_stacks_op_p.c
*/

int				op_pa(t_two_stacks *stacks);
int				op_pb(t_two_stacks *stacks);

/*
** From two_stacks_op_r.c
*/

int				op_ra(t_two_stacks *stacks);
int				op_rb(t_two_stacks *stacks);
int				op_rr(t_two_stacks *stacks);

/*
** From two_stacks_op_rr.c
*/

int				op_rra(t_two_stacks *stacks);
int				op_rrb(t_two_stacks *stacks);
int				op_rrr(t_two_stacks *stacks);

/*
** From two_stacks_do_op.c
*/

t_op_assoc		get_op_assoc(int i);
int				stacks_do_op_assoc(t_two_stacks *stacks, t_op_assoc *op_assoc);
int				stacks_do_op(t_two_stacks *stacks, t_op op);
int				stacks_undo_op(t_two_stacks *stacks);

/*
** From print_solution.c
*/

void			two_stacks_print(t_two_stacks *stacks, int fd);
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

void			solve_big(t_two_stacks *stacks);

/*
** From bruteforce.c
*/

int				solve_bruteforce(t_two_stacks *stacks);

#endif

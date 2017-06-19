/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_do_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:14:25 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 16:14:26 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_assoc	get_op_assoc(int i)
{
	static const t_op_assoc	op_assoc[] = {
		{"sa", O_SA, &op_sa, O_SA, &op_sa},
		{"sb", O_SB, &op_sb, O_SB, &op_sb},
		{"ss", O_SS, &op_ss, O_SS, &op_ss},
		{"pa", O_PA, &op_pa, O_PB, &op_pb},
		{"pb", O_PB, &op_pb, O_PA, &op_pa},
		{"ra", O_RA, &op_ra, O_RRA, &op_rra},
		{"rb", O_RB, &op_rb, O_RRB, &op_rrb},
		{"rr", O_RR, &op_rr, O_RRR, &op_rrr},
		{"rra", O_RRA, &op_rra, O_RA, &op_ra},
		{"rrb", O_RRB, &op_rrb, O_RB, &op_rb},
		{"rrr", O_RRR, &op_rrr, O_RR, &op_rr},
		{NULL, O_UNK, NULL, O_UNK, NULL}
	};

	return (op_assoc[i]);
}

int			stacks_do_op_assoc(t_allocated **a_list, t_two_stacks *stacks,
														t_op_assoc *op_assoc)
{
	t_cll_elem	*elem;
	int			err;

	err = (*(op_assoc->f))(stacks);
	if (err == 0)
	{
		elem = cll_elem_create(a_list, op_assoc->op);
		if (elem)
		{
			cll_push(stacks->op, elem);
			return (0);
		}
		else
			return (1);
	}
	else
		return (1);
}

int			stacks_do_op(t_allocated **a_list, t_two_stacks *stacks, t_op op)
{
	int			i;
	t_op_assoc	op_assoc;

	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i);
		if (op_assoc.op == O_UNK)
			return (1);
		if (op_assoc.op == op)
			break ;
		i++;
	}
	return (stacks_do_op_assoc(a_list, stacks, &op_assoc));
}

int		stacks_undo_op(t_allocated **a_list, t_two_stacks *stacks)
{
	t_op		op;
	t_cll_elem	*elem;
	int			i;
	t_op_assoc	op_assoc;

	elem = cll_pop(stacks->op);
	if (!elem)
		return (1);
	op = elem->value;
	my_malloc_free(a_list, elem);
	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i);
		if (op_assoc.op == O_UNK)
			return (1);
		if (op_assoc.op == op)
			break ;
		i++;
	}
	return ((*(op_assoc.rev_f))(stacks));
}

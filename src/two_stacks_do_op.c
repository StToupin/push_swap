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
#include "ft.h" //

t_op_assoc	get_op_assoc(int i)
{
	static const t_op_assoc	op_assoc[] = {
		{O_SA, "sa", &op_sa, &op_sa},
		{O_SB, "sb", &op_sb, &op_sb},
		{O_SS, "ss", &op_ss, &op_ss},
		{O_PA, "pa", &op_pa, &op_pb},
		{O_PB, "pb", &op_pb, &op_pa},
		{O_RA, "ra", &op_ra, &op_rra},
		{O_RB, "rb", &op_rb, &op_rrb},
		{O_RR, "rr", &op_rr, &op_rrr},
		{O_RRA, "rra", &op_rra, &op_ra},
		{O_RRB, "rrb", &op_rrb, &op_rb},
		{O_RRR, "rrr", &op_rrr, &op_rr},
		{O_END, NULL, NULL, NULL}
	};

	return (op_assoc[i]);
}

int			stacks_do_op(t_allocated **a_list, t_two_stacks *stacks, t_op op)
{
	int			i;
	t_op_assoc	op_assoc;
	t_cll_elem	*elem;

	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i);
		if (op_assoc.op == O_END)
			return (1);
		if (op_assoc.op == op)
			break ;
		i++;
	}
	(*(op_assoc.f))(stacks);
	elem = cll_elem_create(a_list, op);
	if (elem)
		cll_push(stacks->op, elem);
	else
		return (1);
	return (0);
}

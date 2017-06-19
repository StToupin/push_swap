/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 04:56:00 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/11 04:56:03 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	backtracking(t_allocated **a_list, t_two_stacks *stacks, int depth, int max_depth, t_op last_op)
{
	int			i;
	t_op_assoc	op_assoc;
	int			found;
	int			err;

	if (depth == max_depth)
		return (0);
	if (two_stacks_is_sorted(stacks))
		return (1);
	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i);
		if (op_assoc.op == O_UNK)
			break ;
		if (op_assoc.rev_op != last_op)
		{
			err = stacks_do_op(a_list, stacks, op_assoc.op);
			if (err == 0)
			{
				found = backtracking(a_list, stacks, depth + 1, max_depth, op_assoc.op);
				if (found)
					return (1);
				stacks_undo_op(a_list, stacks);
			}
		}
		i++;
	}
	return (0);
}

int			solve_bruteforce(t_allocated **a_list, t_two_stacks *stacks)
{
	int	max_depth;

	max_depth = 0;
	while (1)
	{
		if (backtracking(a_list, stacks, 0, max_depth, O_UNK))
			return (1);
		max_depth++;
	}
}

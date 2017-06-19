/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_op_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:26:26 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:26:28 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circular_linked_list.h"

int	op_sa(t_two_stacks *stacks)
{
	if (stacks->a->n >= 2)
	{
		cll_swap_top(stacks->a);
		return (0);
	}
	else
		return (1);
}

int	op_sb(t_two_stacks *stacks)
{
	if (stacks->b->n >= 2)
	{
		cll_swap_top(stacks->b);
		return (0);
	}
	else
		return (1);
}

int	op_ss(t_two_stacks *stacks)
{
	if (stacks->a->n >= 2 && stacks->b->n >= 2)
	{
		cll_swap_top(stacks->a);
		cll_swap_top(stacks->b);
		return (0);
	}
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_op_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:47:19 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:47:21 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circular_linked_list.h"

int	op_ra(t_two_stacks *stacks)
{
	if (stacks->a->n >= 2)
	{
		cll_rotate(stacks->a);
		return (0);
	}
	else
		return (1);
}

int	op_rb(t_two_stacks *stacks)
{
	if (stacks->b->n >= 2)
	{
		cll_rotate(stacks->b);
		return (0);
	}
	else
		return (1);
}

int	op_rr(t_two_stacks *stacks)
{
	if (stacks->a->n >= 2 && stacks->b->n >= 2)
	{
		cll_rotate(stacks->a);
		cll_rotate(stacks->b);
		return (0);
	}
	else
		return (1);
}

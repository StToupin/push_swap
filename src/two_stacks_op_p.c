/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_op_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:26:26 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:26:28 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circular_linked_list.h"

int	op_pa(t_two_stacks *stacks)
{
	if (stacks->b->n > 0)
	{
		cll_push(stacks->a, cll_pop(stacks->b));
		return (0);
	}
	else
		return (1);
}

int	op_pb(t_two_stacks *stacks)
{
	if (stacks->a->n > 0)
	{
		cll_push(stacks->b, cll_pop(stacks->a));
		return (0);
	}
	else
		return (1);
}

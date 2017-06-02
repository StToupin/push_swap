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

void	op_ra(t_two_stacks *stacks)
{
	cll_rotate(stacks->a);
}

void	op_rb(t_two_stacks *stacks)
{
	cll_rotate(stacks->b);
}

void	op_rr(t_two_stacks *stacks)
{
	cll_rotate(stacks->a);
	cll_rotate(stacks->b);
}

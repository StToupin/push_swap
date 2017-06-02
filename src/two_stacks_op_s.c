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

void	op_sa(t_two_stacks *stacks)
{
	cll_swap_top(stacks->a);
}

void	op_sb(t_two_stacks *stacks)
{
	cll_swap_top(stacks->b);
}

void	op_ss(t_two_stacks *stacks)
{
	cll_swap_top(stacks->a);
	cll_swap_top(stacks->b);
}

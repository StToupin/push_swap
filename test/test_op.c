/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:57:09 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:57:11 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "my_malloc.h"
#include "ft.h"

static void	test_op_p(t_allocated **a_list, t_two_stacks *stacks)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putstr_fd("pb\n", 1);
		stacks_do_op(a_list, stacks, O_PB);
		i++;
	}
	two_stacks_print(stacks, 1);
	ft_putstr_fd("pa\n", 1);
	stacks_do_op(a_list, stacks, O_PA);
	two_stacks_print(stacks, 1);
}

static void	test_op_s(t_allocated **a_list, t_two_stacks *stacks)
{
	ft_putstr_fd("sa\n", 1);
	stacks_do_op(a_list, stacks, O_SA);
	two_stacks_print(stacks, 1);
	ft_putstr_fd("sb\n", 1);
	stacks_do_op(a_list, stacks, O_SB);
	two_stacks_print(stacks, 1);
}

static void	test_op_r(t_allocated **a_list, t_two_stacks *stacks)
{
	ft_putstr_fd("ra\n", 1);
	stacks_do_op(a_list, stacks, O_RA);
	two_stacks_print(stacks, 1);
	ft_putstr_fd("rb\n", 1);
	stacks_do_op(a_list, stacks, O_RB);
	two_stacks_print(stacks, 1);
	ft_putstr_fd("rr\n", 1);
	stacks_do_op(a_list, stacks, O_RR);
	two_stacks_print(stacks, 1);
}

static void	test_op_rr(t_allocated **a_list, t_two_stacks *stacks)
{
	ft_putstr_fd("rra\n", 1);
	stacks_do_op(a_list, stacks, O_RRA);
	two_stacks_print(stacks, 1);
	ft_putstr_fd("rrb\n", 1);
	stacks_do_op(a_list, stacks, O_RRB);
	two_stacks_print(stacks, 1);
	ft_putstr_fd("rrr\n", 1);
	stacks_do_op(a_list, stacks, O_RRR);
	two_stacks_print(stacks, 1);
}

void		test_op(t_allocated **a_list, t_two_stacks *stacks)
{
	if (stacks)
	{
		test_op_p(a_list, stacks);
		test_op_r(a_list, stacks);
		test_op_rr(a_list, stacks);
		test_op_s(a_list, stacks);
	}
}
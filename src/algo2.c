/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:48:17 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/07 16:48:18 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int		do_route(t_allocated **a_list, t_two_stacks *stacks,
						t_route route)
{
	while (route.a != 0)
		if (route.a * route.b > 0)
		{
			if (stacks_do_op(a_list, stacks, (route.a > 0) ? O_RR : O_RRR))
				return (1);
			route = (t_route){route.a + ((route.a > 0) ? -1 : 1),
							route.b + ((route.a > 0) ? -1 : 1), route.len};
		}
		else
		{
			if (stacks_do_op(a_list, stacks, (route.a > 0) ? O_RA : O_RRA))
				return (1);
			route.a += (route.a > 0) ? -1 : 1;
		}
	while (route.b != 0)
	{
		if (stacks_do_op(a_list, stacks, (route.b > 0) ? O_RB : O_RRB))
			return (1);
		route.b += (route.b > 0) ? -1 : 1;
	}
	return (0);
}

static void		push_swap(t_allocated **a_list, t_two_stacks *stacks)
{
	t_route			route[stacks->a->n];
	t_cll_elem		*elem;
	int				i;
	t_index_value	best_route;

	best_route = (t_index_value){-1, INT_MAX};
	elem = stacks->a->top->up;
	i = -1;
	while (++i < stacks->a->n)
	{
		route[i] = find_best_route(stacks, i, elem->value);
		if (route[i].len < best_route.value)
			best_route = (t_index_value){i, route[i].len};
		elem = elem->up;
	}
	do_route(a_list, stacks, route[best_route.index]);
	stacks_do_op(a_list, stacks, O_PB);
}

static void		push_back(t_allocated **a_list, t_two_stacks *stacks)
{
	t_index_value	max_b;
	int				i;
	t_cll_elem		*elem;
	int				dist_b;

	elem = stacks->b->top->up;
	max_b = (t_index_value){0, elem->value};
	i = 0;
	while (++i < stacks->b->n)
	{
		if (elem->value > max_b.value)
			max_b = (t_index_value){i, elem->value};
		elem = elem->up;
	}
	if (max_b.index + 1 < stacks->b->n - max_b.index - 1)
		dist_b = -max_b.index - 1;
	else
		dist_b = stacks->b->n - max_b.index - 1;
	do_route(a_list, stacks, (t_route){0, dist_b, 0});
	stacks_do_op(a_list, stacks, O_PA);
}

void			solve_big(t_allocated **a_list, t_two_stacks *stacks)
{
	while (stacks->a->n > 0)
		push_swap(a_list, stacks);
	while (stacks->b->n > 0)
		push_back(a_list, stacks);
}
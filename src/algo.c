/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:33:02 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/05 14:33:04 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int		calc_route_len(int dist_a, int dist_b)
{
	int dist;

	if (dist_a >= dist_b && dist_b >= 0)
		return (dist_a);
	else if (dist_b >= dist_a && dist_a >= 0)
		return (dist_b);
	else if (dist_a <= dist_b && dist_b <= 0)
		return (-dist_a);
	else if (dist_b <= dist_a && dist_a <= 0)
		return (-dist_b);
	else
	{
		dist = (dist_a >= 0) ? dist_a : (-dist_a);
		dist += (dist_b >= 0) ? dist_b : (-dist_b);
		return (dist);
	}
}

static void		find_min_max(t_cll *stack,
								t_index_value *min, t_index_value *max)
{
	t_cll_elem	*elem;
	int			i;

	elem = stack->top->up;
	*min = (t_index_value){0., elem->value};
	*max = (t_index_value){0., elem->value};
	i = 0;
	while (i < stack->n)
	{
		if (elem->value < min->value)
			*min = (t_index_value){i, elem->value};
		if (elem->value > max->value)
			*max = (t_index_value){i, elem->value};
		elem = elem->up;
		i++;
	}
}

static int		place_to_insert(t_cll *stack, int value)
{
	t_cll_elem	*elem;
	int			i;

	elem = stack->top->up;
	i = 0;
	while (i < stack->n)
	{
		if (elem->value < value && value < elem->up->value)
			return (i);
		elem = elem->up;
		i++;
	}
	return (-1);
}

static void		john_b_route(t_cll *stack_b, int val_a, int dist_b[2])
{
	t_index_value	min_b;
	t_index_value	max_b;
	int				i;

	find_min_max(stack_b, &min_b, &max_b);
	if (val_a < min_b.value)
		i = min_b.index;
	else if (val_a > max_b.value)
		i = max_b.index + 1;
	else
		i = place_to_insert(stack_b, val_a) + 1;
	dist_b[0] = -i;
	dist_b[1] = stack_b->n - i;
}

t_route			find_best_route(t_two_stacks *stacks, int i_a, int val_a)
{
	int				d_a[2];
	int				d_b[2];
	t_route			route[4];
	t_index_value	min_len;

	if (stacks->b->n == 0)
		return ((t_route){0, 0, 0});
	d_a[0] = stacks->a->n - i_a - 1;
	d_a[1] = -i_a - 1;
	john_b_route(stacks->b, val_a, d_b);
	route[0] = (t_route){d_a[0], d_b[0], calc_route_len(d_a[0], d_b[0])};
	route[1] = (t_route){d_a[0], d_b[1], calc_route_len(d_a[0], d_b[1])};
	route[2] = (t_route){d_a[1], d_b[0], calc_route_len(d_a[1], d_b[0])};
	route[3] = (t_route){d_a[1], d_b[1], calc_route_len(d_a[1], d_b[1])};
	min_len = (t_index_value){-1, INT_MAX};
	if (route[0].len < min_len.value)
		min_len = (t_index_value){0, route[0].len};
	if (route[1].len < min_len.value)
		min_len = (t_index_value){1, route[1].len};
	if (route[2].len < min_len.value)
		min_len = (t_index_value){2, route[2].len};
	if (route[3].len < min_len.value)
		min_len = (t_index_value){3, route[3].len};
	return (route[min_len.index]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:11:44 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 14:11:47 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circular_linked_list.h"
#include "my_malloc.h"
#include "ft.h"

void		two_stacks_free(t_two_stacks *stacks, int verbose)
{
	int cleaned;

	if (stacks == NULL)
		return ;
	cll_free(&(stacks->a_list), &(stacks->a));
	cll_free(&(stacks->a_list), &(stacks->b));
	cll_free(&(stacks->a_list), &(stacks->op));
	cleaned = my_malloc_cleanup(&(stacks->a_list));
	if (verbose)
		ft_putnbr_fd(cleaned, 1);
	if (verbose)
		ft_putstr_fd(" pointer(s) left.\n", 1);
}

void		two_stacks_create(t_two_stacks *stacks, int verbose)
{
	my_malloc_init(&(stacks->a_list));
	stacks->a = cll_create(&(stacks->a_list));
	stacks->b = cll_create(&(stacks->a_list));
	stacks->op = cll_create(&(stacks->a_list));
	if (!stacks->a || !stacks->b || !stacks->op)
		two_stacks_free(stacks, verbose);
}

static int	cll_list_contains(t_cll *cll, int number)
{
	t_cll_elem	*elem;
	int			i;

	if (cll->n > 0)
	{
		elem = cll->top;
		elem = cll->top->up;
		i = 0;
		while (i < cll->n)
		{
			if (elem->value == number)
				return (1);
			elem = elem->up;
			i++;
		}
	}
	return (0);
}

int			two_stacks_from_strings(t_two_stacks *stacks, int n, char **s,
																	int verbose)
{
	t_cll_elem		*elem;
	int				i;
	int				value;

	two_stacks_create(stacks, verbose);
	i = -1;
	while (++i < n)
	{
		if (ft_str_to_int(s[n - i - 1], &value))
			return (1);
		if (cll_list_contains(stacks->a, value))
			return (1);
		if (!(elem = cll_elem_create(&(stacks->a_list), value)))
		{
			two_stacks_free(stacks, verbose);
			return (1);
		}
		cll_push(stacks->a, elem);
	}
	return (0);
}

int			two_stacks_is_sorted(t_two_stacks *stacks)
{
	t_cll_elem	*elem;
	int			i;

	if (stacks->b->n > 0)
		return (0);
	if (stacks->a->n < 2)
		return (1);
	elem = stacks->a->top->up;
	i = 0;
	while (i < stacks->a->n - 1)
	{
		if (elem->value < elem->up->value)
			return (0);
		elem = elem->up;
		i++;
	}
	return (1);
}

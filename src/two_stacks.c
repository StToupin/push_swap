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

void			two_stacks_free(t_allocated **a_list, t_two_stacks **stacks)
{
	if (*stacks == NULL)
		return ;
	cll_free(a_list, &((*stacks)->a));
	cll_free(a_list, &((*stacks)->b));
	cll_free(a_list, &((*stacks)->op));
	my_malloc_free(a_list, *stacks);
	*stacks = NULL;
}

t_two_stacks	*two_stacks_create(t_allocated **a_list)
{
	t_two_stacks	*stacks;

	stacks = (t_two_stacks*)my_malloc(a_list, sizeof(t_two_stacks));
	if (stacks)
	{
		stacks->a = cll_create(a_list);
		stacks->b = cll_create(a_list);
		stacks->op = cll_create(a_list);
		if (!stacks->a || !stacks->b || !stacks->op)
			two_stacks_free(a_list, &stacks);
	}
	return (stacks);
}

t_two_stacks	*two_stacks_from_strings(t_allocated **a_list, int n, char **s)
{
	t_two_stacks	*stacks;
	t_cll_elem		*elem;
	int				i;
	int				value;

	stacks = two_stacks_create(a_list);
	if (stacks)
	{
		i = -1;
		while (++i < n)
		{
			if (ft_str_to_int(s[n - i - 1], &value))
			{
				two_stacks_free(a_list, &stacks);
				break ;
			}
			if (!(elem = cll_elem_create(a_list, value)))
			{
				two_stacks_free(a_list, &stacks);
				break ;
			}
			cll_push(stacks->a, elem);
		}
	}
	return (stacks);
}

void			two_stacks_print(t_two_stacks *stacks, int fd)
{
	if (stacks == NULL)
		ft_putstr_fd("(null)\n", 1);
	else
	{
		ft_putstr_fd("A: ", fd);
		cll_print(stacks->a, fd);
		ft_putstr_fd(", B: ", fd);
		cll_print(stacks->b, fd);
		ft_putstr_fd("\n", fd);
	}
}

int				two_stacks_is_sorted(t_two_stacks *stacks)
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

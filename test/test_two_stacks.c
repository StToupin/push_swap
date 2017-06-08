/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_two_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:00:45 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:00:46 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft.h"
#include "my_malloc.h"
#include "test.h"

void		print_op_list(t_cll *op_list)
{
	t_cll_elem	*elem;
	t_op_assoc	op_assoc;
	int			i;
	int			j;

	if (op_list->n == 0)
		return ;
	elem = op_list->top->up;
	i = 0;
	while (i < op_list->n)
	{
		j = 0;
		while (1)
		{
			op_assoc =get_op_assoc(j);
			if (op_assoc.op == O_END)
				break ;
			if (op_assoc.op == elem->value)
			{
				ft_putstr_fd(op_assoc.name, 1);
				ft_putstr_fd(" ", 1);
			}
			j++;
		}
		elem = elem->up;
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void		test_two_stacks(int n, char **s)
{
	t_two_stacks	*stacks;
	t_allocated		*a_list;
	int				cleaned;

	my_malloc_init(&a_list);

	ft_putstr_fd("Generating stacks from arguments\n", 1);
	stacks = two_stacks_from_strings(&a_list, n, s);
	two_stacks_print(stacks, 1);
	test_op(&a_list, stacks);
	ft_putstr_fd("Operation history: ", 1);
	print_op_list(stacks->op);
	ft_putstr_fd("Deleting stacks\n", 1);
	two_stacks_free(&a_list, &stacks);
	ft_putstr_fd("Exiting gracefully\n", 1);
	cleaned = my_malloc_cleanup(&a_list);
	ft_putnbr_fd(cleaned, 1);
	ft_putstr_fd(" freed pointer(s).\n\n", 1);
}
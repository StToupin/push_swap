/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:56:23 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/08 16:56:24 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "push_swap.h"

void		two_stacks_print(t_two_stacks *stacks, int fd)
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

static void	print_op(t_op op, int fd)
{
	t_op_assoc	op_assoc;
	int			i;

	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i++);
		if (op_assoc.op == op)
		{
			ft_putstr_fd(op_assoc.name, fd);
			ft_putstr_fd("\n", fd);
			break ;
		}
		if (op_assoc.op == O_UNK)
		{
			ft_putstr_fd("UNKNOWN\n", fd);
			break ;
		}
	}
}

void		print_solution(t_two_stacks *stacks, int fd)
{
	t_cll_elem	*elem;
	int			i;

	if (stacks->op->n == 0)
		return ;
	elem = stacks->op->top->up;
	i = -1;
	while (++i < stacks->op->n)
	{
		print_op(elem->value, fd);
		elem = elem->up;
	}
}

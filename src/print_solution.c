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

void	print_solution(t_two_stacks	*stacks, int fd)
{
	t_cll_elem	*elem;
	t_op_assoc	op_assoc;
	int			i;
	int			j;

	elem = stacks->op->top->up;
	i = -1;
	while (++i < stacks->op->n)
	{
		j = 0;
		while (1)
		{
			op_assoc = get_op_assoc(j++);
			if (op_assoc.op == elem->value)
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
		elem = elem->up;
	}
}
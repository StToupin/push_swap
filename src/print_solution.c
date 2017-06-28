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
#include "get_next_byte.h"

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

static void	ft_putstr_endl_of(t_openfile *of, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write_next_byte(of, str[i]);
		i++;
	}
	write_next_byte(of, '\n');
}

static void	print_op(t_op op, t_openfile *of)
{
	t_op_assoc	op_assoc;
	int			i;

	i = 0;
	while (1)
	{
		op_assoc = get_op_assoc(i++);
		if (op_assoc.op == op)
		{
			ft_putstr_endl_of(of, op_assoc.name);
			break ;
		}
		if (op_assoc.op == O_UNK)
		{
			ft_putstr_endl_of(of, "UNKNOWN");
			break ;
		}
	}
}

void		print_solution(t_two_stacks *stacks, int fd)
{
	t_cll_elem	*elem;
	t_openfile	of;
	int			i;

	get_next_byte_init(&of, fd);
	if (stacks->op->n == 0)
		return ;
	elem = stacks->op->top->up;
	i = -1;
	while (++i < stacks->op->n)
	{
		print_op(elem->value, &of);
		elem = elem->up;
	}
	of.eof = 1;
	write_next_byte(&of, 0);
}

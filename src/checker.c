/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:11:21 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/08 17:11:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft.h"

static int	do_op(t_two_stacks *stacks, char *op_name, int verbose)
{
	int			n_op;
	t_op_assoc	op_assoc;

	n_op = 0;
	while (1)
	{
		op_assoc = get_op_assoc(n_op++);
		if (op_assoc.op == O_UNK)
			return (1);
		if (ft_strcmp(op_name, op_assoc.name) == 0)
		{
			if (verbose)
				ft_putstr_fd("Doing ", 1);
			if (verbose)
				ft_putstr_fd(op_name, 1);
			if (stacks_do_op_assoc(stacks, &op_assoc))
				return (1);
			if (verbose)
				ft_putstr_fd(": ", 1);
			if (verbose)
				two_stacks_print(stacks, 1);
			break ;
		}
	}
	return (0);
}

static int	execute_program(t_two_stacks *stacks, int verbose)
{
	t_openfile	of;
	char		op[4];
	int			ret;

	get_next_byte_init(&of, STDIN_FILENO);
	while (1)
	{
		ret = get_next_op(&of, op);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (1);
		if (do_op(stacks, op, verbose) == 1)
			return (1);
	}
	return (0);
}

static void	checker(int argc, char **argv, int verbose)
{
	t_two_stacks	stacks;
	int				err;

	err = two_stacks_from_strings(&stacks, argc - 1, argv + 1, verbose);
	if (err == 0)
	{
		if (stacks.a->n > 0)
		{
			if (execute_program(&stacks, verbose))
				ft_putstr_fd("Error\n", 2);
			else if (two_stacks_is_sorted(&stacks))
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
		}
	}
	else
		ft_putstr_fd("Error\n", 2);
	two_stacks_free(&stacks, verbose);
}

int			main(int argc, char **argv)
{
	int				verbose;

	verbose = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		verbose = 1;
		argc -= 1;
		argv += 1;
	}
	checker(argc, argv, verbose);
	return (0);
}

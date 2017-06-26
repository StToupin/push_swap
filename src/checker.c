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
#include "get_next_byte.h"
#include "push_swap.h"
#include "my_malloc.h"
#include "ft.h"

static int	do_op(t_allocated **a_list, t_two_stacks *stacks, char *op_name,
																	int verbose)
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
			if (stacks_do_op_assoc(a_list, stacks, &op_assoc))
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

static void	get_next_op(t_openfile *of, char op[4])
{
	char	dummy;

	get_next_byte(of, op);
	get_next_byte(of, op + 1);
	get_next_byte(of, op + 2);
	op[3] = '\0';
	if (op[2] == '\n')
		op[2] = '\0';
	else
		get_next_byte(of, &dummy);
}

static int	execute_program(t_allocated **a_list, t_two_stacks *stacks,
																	int verbose)
{
	t_openfile	of;
	char		op[4];

	get_next_byte_init(&of, STDIN_FILENO);
	while (1)
	{
		get_next_op(&of, op);
		if (of.buf_size == 0)
			break ;
		if (do_op(a_list, stacks, op, verbose) == 1)
			return (1);
	}
	return (0);
}

static void	push_swap(t_allocated **a_list, int argc, char **argv, int verbose)
{
	t_two_stacks	*stacks;

	stacks = two_stacks_from_strings(a_list, argc - 1, argv + 1);
	if (stacks)
	{
		if (execute_program(a_list, stacks, verbose))
			ft_putstr_fd("ERROR\n", 2);
		else if (two_stacks_is_sorted(stacks))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("ERROR\n", 2);
	two_stacks_free(a_list, &stacks);
}

int			main(int argc, char **argv)
{
	t_allocated		*a_list;
	int				cleaned;
	int				verbose;

	verbose = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		verbose = 1;
		argc -= 1;
		argv += 1;
	}
	my_malloc_init(&a_list);
	push_swap(&a_list, argc, argv, verbose);
	cleaned = my_malloc_cleanup(&a_list);
	if (verbose)
		ft_putnbr_fd(cleaned, 1);
	if (verbose)
		ft_putstr_fd(" freed pointer(s).\n", 1);
	return (0);
}

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
#include "my_malloc.h"
#include "get_next_line.h"
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
		}
	}
	return (0);
}

static int	execute_program(t_allocated **a_list, t_two_stacks *stacks,
																	int verbose)
{
	char	*line;
	int		len;

	(void)stacks;
	while (get_next_line(a_list, STDIN_FILENO, &line, &len) == 1)
	{
		if (len == 0)
			break ;
		else if (len == 2 || len == 3)
			do_op(a_list, stacks, line, verbose);
		else
		{
			my_malloc_free(a_list, line);
			return (1);
		}
		my_malloc_free(a_list, line);
	}
	my_malloc_free(a_list, line);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:50:16 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:50:36 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "my_malloc.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_two_stacks	stacks;
	int				verbose;

	verbose = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		verbose = 1;
		argc -= 1;
		argv += 1;
	}
	if (two_stacks_from_strings(&stacks, argc - 1, argv + 1, verbose) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!two_stacks_is_sorted(&stacks))
	{
		if (stacks.a->n <= 6)
			solve_bruteforce(&stacks);
		else
			solve_big(&stacks);
	}
	print_solution(&stacks, 1);
	two_stacks_free(&stacks, verbose);
	return (0);
}

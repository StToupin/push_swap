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

int	main(int argc, char **argv)
{
	t_allocated		*a_list;
	t_two_stacks	*stacks;
	int				cleaned;
	int				verbose;

	verbose = 0;
	if (argc >= 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		verbose = 1;
		argc -= 1;
		argv += 1;
	}
	my_malloc_init(&a_list);
	stacks = two_stacks_from_strings(&a_list, argc - 1, argv + 1);
	if (stacks && !two_stacks_is_sorted(stacks))
	{
		if (stacks->a->n <= 6)
			solve_bruteforce(&a_list, stacks);
		else
			solve_big(&a_list, stacks);
	}
	print_solution(stacks, 1);
	two_stacks_free(&a_list, &stacks);
	cleaned = my_malloc_cleanup(&a_list);
	if (verbose)
		ft_putnbr_fd(cleaned, 1);
	if (verbose)
		ft_putstr_fd(" freed pointer(s).\n", 1);
	return (0);
}

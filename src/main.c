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
#include "test.h"

int	main(int argc, char **argv)
{
	//test_circular_linked_list();
	//test_two_stacks(argc - 1, argv + 1);
	t_allocated		*a_list;
	t_two_stacks	*stacks;
	int				cleaned;

	my_malloc_init(&a_list);
	stacks = two_stacks_from_strings(&a_list, argc - 1, argv + 1);
	solve_big(&a_list, stacks);
	print_solution(stacks, 1);
	two_stacks_free(&a_list, &stacks);
	cleaned = my_malloc_cleanup(&a_list);
	//ft_putnbr_fd(cleaned, 1);
	//ft_putstr_fd(" freed pointer(s).\n", 1);
	return (0);
}

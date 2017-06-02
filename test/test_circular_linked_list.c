/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_circular_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:00:37 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 15:00:38 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "my_malloc.h"
#include "circular_linked_list.h"

static void print_cll(t_cll *cll)
{
	cll_print(cll, 1);
	ft_putstr_fd("\n", 1);
}

static void init(t_allocated **a_list, t_cll **cll)
{
	int values[] = {4, 8, 15, 16, 23, 42};
	int i;

	my_malloc_init(a_list);
	ft_putstr_fd("Creating empty circular linked list\n", 1);
	*cll = cll_create(a_list);
	print_cll(*cll);
	ft_putstr_fd("Inserting values\n", 1);
	i = 0;
	while (i < 6)
	{
		cll_push(*cll, cll_elem_create(a_list, values[i]));
		cll_print(*cll, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	print_cll(*cll);
}

static void clean(t_allocated **a_list, t_cll **cll)
{
	int cleaned;

	ft_putstr_fd("Removing elements\n", 1);
	cll_free(a_list, cll);
	ft_putstr_fd("Exiting gracefully\n", 1);
	cleaned = my_malloc_cleanup(a_list);
	ft_putnbr_fd(cleaned, 1);
	ft_putstr_fd(" freed pointer(s).\n\n", 1);
}

void		test_circular_linked_list(void)
{
	t_allocated	*a_list;
	t_cll *cll;

	cll = NULL;
	init(&a_list, &cll);
	ft_putstr_fd("Rotation\n", 1);
	cll_rotate(cll);
	print_cll(cll);
	ft_putstr_fd("Reverse rotation\n", 1);
	cll_reverse_rotate(cll);
	print_cll(cll);
	ft_putstr_fd("Swap top\n", 1);
	cll_swap_top(cll);
	print_cll(cll);
	clean(&a_list, &cll);
}

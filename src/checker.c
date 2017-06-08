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

#include "my_malloc.h"
#include "get_next_line.h"
#include "ft.h"

int	do_op(t_allocated **a_list, t_two_stacks *stacks)
{
	char	*line;

	while (get_next_line(a_list, STDIN_FILENO, &line) == 1)
	{
		ft_putstr(line, fd);
		ft_putstr("\n");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_allocated		*a_list;
	t_two_stacks	*stacks;
	int				cleanup;

	my_malloc_init(&a_list);
	stacks = two_stacks_from_strings(&a_list, argc - 1, argv + 1);
	if (stacks)
		do_op(&a_list, stacks);
	else
		ft_putstr_fd("ERROR\n", 2);
	cleaned = my_malloc_cleanup(&a_list);
	ft_putnbr_fd(cleaned, 1);
	ft_putstr_fd(" freed pointer(s).\n", 1);
	return (0);
}
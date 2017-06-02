/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_op.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:54:30 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:58:17 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"
#include "ft.h"

void	cll_swap_top(t_cll *cll)
{
	int	save;

	if (cll == NULL || cll->n < 2)
		return ;
	save = cll->top->value;
	cll->top->value = cll->top->down->value;
	cll->top->down->value = save;
}

void	cll_rotate(t_cll *cll)
{
	if (cll == NULL || cll->n < 2)
		return ;
	cll->top = cll->top->down;
}

void	cll_reverse_rotate(t_cll *cll)
{
	if (cll == NULL || cll->n < 2)
		return ;
	cll->top = cll->top->up;
}

void	cll_transfer_top(t_cll *src, t_cll *dest)
{
	if (src == NULL || dest == NULL || src->n == 0)
		return ;
	cll_push(dest, cll_pop(src));
}

void		cll_print(t_cll *cll, int fd)
{
	t_cll_elem	*elem;
	int			i;

	ft_putstr_fd("[", fd);
	if (cll == NULL)
		ft_putstr_fd("(null)", 1);
	else if (cll->n > 0)
	{
		elem = cll->top;
		elem = cll->top->up;
		i = 0;
		while (i < cll->n)
		{
			if (i > 0)
				ft_putstr_fd(", ", fd);
			ft_putnbr_fd(elem->value, fd);
			elem = elem->up;
			i++;
		}
	}
	ft_putstr_fd("]", fd);
}

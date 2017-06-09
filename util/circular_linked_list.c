/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:19:43 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:19:44 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"
#include "my_malloc.h"

t_cll_elem	*cll_elem_create(t_allocated **a_list, int value)
{
	t_cll_elem	*elem;

	elem = (t_cll_elem*)my_malloc(a_list, sizeof(t_cll_elem));
	if (elem)
	{
		elem->up = NULL;
		elem->down = NULL;
		elem->value = value;
	}
	return (elem);
}

t_cll		*cll_create(t_allocated **a_list)
{
	t_cll	*cll;

	cll = (t_cll*)my_malloc(a_list, sizeof(t_cll));
	if (cll)
	{
		cll->top = NULL;
		cll->n = 0;
	}
	return (cll);
}

void		cll_push(t_cll *cll, t_cll_elem *elem)
{
	if (cll->n == 0)
	{
		elem->up = elem;
		elem->down = elem;
		cll->top = elem;
	}
	else
	{
		elem->down = cll->top;
		elem->up = cll->top->up;
		cll->top->up->down = elem;
		cll->top->up = elem;
		cll->top = elem;
	}
	cll->n++;
}

t_cll_elem	*cll_pop(t_cll *cll)
{
	t_cll_elem	*elem;

	if (cll->n == 0)
		return (NULL);
	else if (cll->n == 1)
	{
		elem = cll->top;
		elem->up = NULL;
		elem->down = NULL;
		cll->top = NULL;
	}
	else
	{
		elem = cll->top;
		elem->up->down = elem->down;
		elem->down->up = elem->up;
		cll->top = elem->down;
	}
	cll->n--;
	return (elem);
}

void		cll_free(t_allocated **a_list, t_cll **cll)
{
	if (*cll == NULL)
		return ;
	while ((*cll)->n > 0)
		my_malloc_free(a_list, cll_pop(*cll));
	my_malloc_free(a_list, *cll);
	*cll = NULL;
}

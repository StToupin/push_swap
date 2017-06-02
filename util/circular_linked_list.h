/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:17:11 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:19:35 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_LINKED_LIST
# define CIRCULAR_LINKED_LIST

# include "my_malloc.h"

typedef struct	s_cll_elem
{
	struct s_cll_elem	*up;
	struct s_cll_elem	*down;
	int					value;
}				t_cll_elem;

typedef struct	s_cll
{
	t_cll_elem	*top;
	int			n;
}				t_cll;

/*
** From circular_linked_list.c
*/

t_cll_elem	*cll_elem_create(t_allocated **a_list, int value);
t_cll		*cll_create(t_allocated **a_list);
void		cll_push(t_cll *cll, t_cll_elem *elem);
t_cll_elem	*cll_pop(t_cll *cll);
void		cll_free(t_allocated **a_list, t_cll **cll);
t_cll		*cll_clone(t_allocated **a_list, t_cll *src);

/*
** From circular_linked_list_op.c
*/

void		cll_swap_top(t_cll *cll);
void		cll_rotate(t_cll *cll);
void		cll_reverse_rotate(t_cll *cll);
void		cll_transfer_top(t_cll *src, t_cll *dest);
void		cll_print(t_cll *cll, int fd);

#endif

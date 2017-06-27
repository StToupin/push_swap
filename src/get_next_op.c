/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:34:00 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/27 10:34:01 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_byte.h"

/*
** 1 = ok
** 0 = eof
** -1 = *result not in accepted or read error
*/

static int	read_or_die(t_openfile *of, char *accepted, char *result)
{
	int ret;
	int ok;
	int i;

	ret = get_next_byte(of, result);
	if (ret <= 0)
		return (ret);
	ok = 0;
	i = 0;
	while (accepted[i] != '\0')
	{
		if (*result == accepted[i])
		{
			ok = 1;
			break ;
		}
		i++;
	}
	if (*result == '\n')
		*result = '\0';
	if (ok)
		return (1);
	else
		return (-1);
}

int			get_next_op(t_openfile *of, char op[4])
{
	int		ret;

	op[0] = '\0';
	op[1] = '\0';
	op[2] = '\0';
	op[3] = '\0';
	if ((ret = read_or_die(of, "prs", &(op[0]))) <= 0)
		return (ret);
	if (op[0] == 'p' && (ret = read_or_die(of, "ab", &(op[1]))) <= 0)
		return (ret);
	else if (op[0] == 'r' && (ret = read_or_die(of, "abr", &(op[1]))) <= 0)
		return (ret);
	else if (op[0] == 's' && (ret = read_or_die(of, "abs", &(op[1]))) <= 0)
		return (ret);
	if (op[0] == 'r' && op[1] == 'r')
	{
		if ((ret = read_or_die(of, "abr\n", &(op[2]))) <= 0)
			return (ret);
		if (op[2] != '\0' && (ret = read_or_die(of, "\n", &(op[3]))) <= 0)
			return (ret);
	}
	else if ((ret = read_or_die(of, "\n", &(op[2]))) <= 0)
		return (ret);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:33:36 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:33:41 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int			ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	write(fd, str, len);
	return (1);
}

static void	print_digit(int n, int fd)
{
	char digit;

	if (n == 0)
		return ;
	print_digit(n / 10, fd);
	if (n >= 0)
		digit = ('0' + (n % 10));
	else
		digit = ('0' - (n % 10));
	write(fd, &digit, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	else
		print_digit(n, fd);
}

int			ft_str_to_int(char *str, int *nbr)
{
	int		i;
	char	c;
	int		sign;

	*nbr = 0;
	i = 0;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-')
		i++;
	while (str[i] != 0)
	{
		c = str[i];
		if (c >= '0' && c <= '9')
		{
			if ((sign == 1 && *nbr > (INT_MAX - c + '0') / 10)
				|| (sign == -1 && *nbr < (INT_MIN + c - '0') / 10))
				return (1);
			*nbr = (*nbr * 10) + (c - '0') * sign;
		}
		else
			return (1);
		i++;
	}
	return (0);
}

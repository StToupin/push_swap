/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:33:43 by stoupin           #+#    #+#             */
/*   Updated: 2017/06/02 13:33:51 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_str_to_int(char *str, int *nbr);
int		ft_strcmp(char *s1, char *s2);

#endif

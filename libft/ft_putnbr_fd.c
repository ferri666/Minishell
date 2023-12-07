/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:32:55 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/05 16:29:10 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_number(int nbr, int fd)
{
	char	*base;
	char	num;
	int		remainder;

	base = "0123456789";
	if (nbr / 10 != 0)
		print_number((nbr / 10), fd);
	remainder = nbr % 10;
	if (remainder < 0)
		remainder = -remainder;
	num = base[remainder];
	ft_putchar_fd(num, fd);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
		ft_putchar_fd('-', fd);
	print_number(nbr, fd);
}

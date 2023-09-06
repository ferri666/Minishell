/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:44:47 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 16:19:25 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, int i)
{
	int	print_length;

	print_length = 0;
	if (i == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (i == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (i == 'p')
		print_length += ft_printptr(va_arg(args, unsigned long long));
	else if (i == 'd' || i == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (i == 'u')
		print_length += ft_printunsign(va_arg(args, unsigned int));
	else if (i == 'x' || i == 'X')
		print_length += ft_printhex(va_arg(args, unsigned int), i);
	else if (i == '%')
		print_length += ft_printpercent();
	return (print_length);
}

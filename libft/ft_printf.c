/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:55:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 16:15:22 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printpercent(void)
{
	return (write(1, "%", 1));
}

static void	ft_printnull(void)
{
	write(1, "(null)", 6);
}

int	ft_printstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		ft_printnull();
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	va_list		args;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += ft_format(args, format[i + 1]);
			i++;
		}
		else
			ret += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:49:39 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/01 13:20:46 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces(const char *str)
{
	int	sp_nb;

	sp_nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\v' || *str == '\r')
	{
		sp_nb++;
		str++;
	}
	return (sp_nb);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	n;

	sign = 1;
	num = 0;
	n = ft_spaces(str);
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign *= -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		num *= 10;
		num += str[n] - '0';
		n++;
	}
	return (sign * num);
}
/*
test
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("ft_atoi: %d\n", ft_atoi("    1234f7"));
	printf("atoi: %d\n", atoi("    1234f7"));
}
*/
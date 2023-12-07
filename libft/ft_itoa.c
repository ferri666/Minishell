/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:26:35 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = 10;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / remainder;
	}
	return (i);
}

static int	absolut(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	len;

	len = get_len(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	res[len] = 0;
	if (n == 0)
		*res = '0';
	if (n < 0)
		*res = '-';
	len--;
	while (len >= 0 && n != 0)
	{
		*(res + len) = '0' + absolut(n % 10);
		n = (n / 10);
		len--;
	}
	return (res);
}
/*
int	main(void)
{
	printf("106 = %s", ft_itoa(-106));
	//printf("-1234 = %s", ft_itoa(-1234));
	return (0);
}
*/
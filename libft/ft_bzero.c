/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:21:17 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t len)
{
	size_t				i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	frase1[50];
	char	frase2[50];

	bzero(frase1, 5);
	ft_bzero(frase2, 5);
	printf(" %s\n %s\n", frase1, frase2);
	return (0);
}
*/
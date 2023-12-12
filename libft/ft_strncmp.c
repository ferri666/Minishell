/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:04:12 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/09 11:29:46 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(int car)
{
	if (car < 0)
		car += 256;
	return (car);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		c1;
	int		c2;

	i = 0;
	if (n > ft_strlen(s1))
		n = ft_strlen(s1) + 1;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2) + 1;
	while (i < n)
	{
		c1 = ft_convert(s1[i]);
		c2 = ft_convert(s2[i]);
		if (c1 < c2)
			return (-1);
		else if (c1 > c2)
			return (1);
		i++;
	}
	return (0);
}

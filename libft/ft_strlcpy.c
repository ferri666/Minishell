/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:25:07 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
	{
		return (len_src);
	}
	if (size != 0 && len_src != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
int	main(void)
{
	char				frase1[] = "asrgDg";
	char				frase2[] = "RTSSGD";
	unsigned int		res1;
	unsigned int		res2;

	res2 = strlcpy(frase1, frase2, 0);
	printf ("%d\n%s\n", res2, frase1);
	res1 = ft_strlcpy(frase1, frase2, 0);
	printf ("%d\n%s\n", res1, frase1);
}
*/
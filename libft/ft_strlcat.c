/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:43:58 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		len_dest;
	size_t		len_src;
	size_t		off;

	i = 0;
	len_dest = ft_strlen(dest);
	off = len_dest;
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	if (size > 0)
	{
		while (*(src + i) != '\0')
		{
			if (off == (size - 1))
				break ;
			*(dest + off) = *(src + i);
			off++;
			i++;
		}
	}
	*(dest + off) = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	char dst[50] = "nieve ";
	char dst1[50] = "nieve ";
  	printf("%lu --> %s\n", ft_strlcat(dst,"blanca",5),dst);
	printf("%lu --> %s\n", strlcat(dst1,"blanca", 5),dst1);
	return (0);
}
*/
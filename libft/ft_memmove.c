/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:50:40 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		i = len - 1;
		while (len--)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return ((void *)dst);
}
/*
int main (void) {
   const char dest[] = "lorem ipsum dolor sit amet";
   const char src[]  = "nanananana";
   const char dest2[] = "lorem ipsum dolor sit amet";
   const char src2[]  = "nananana";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove((void *)0, (void *)0, 8);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   printf("Before ft_memmove dest = %s, src = %s\n", dest2, src2);
   ft_memmove((void *)0, (void *)0, 8);
   printf("After ft_memmove dest = %s, src = %s\n", dest2, src2);

   return(0);
}
*/
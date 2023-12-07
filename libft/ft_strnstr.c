/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:18:29 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/01 13:19:30 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t			n;
	size_t			p;
	unsigned int	lenght;

	n = 0;
	p = 0;
	lenght = len;
	if (to_find[0] == 0)
		return ((char *)str);
	while (*(str + n) && n < lenght)
	{
		if (*(str + n) == *(to_find + p))
		{
			while ((*(str + n + p) == *(to_find + p)) && (n + p < lenght)
				&& (*(str + n + p)))
			{
				if (*(to_find + p + 1) == 0)
					return ((char *)(str + n));
				p++;
			}
			p = 0;
		}
		n++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", strnstr("Esto es esto que es esto estoesgfdg","estoes", -1));
	printf("%s\n", ft_strnstr("Esto es esto que es esto estoesgfdg","estoes", -1));
	return (0);
}
*/
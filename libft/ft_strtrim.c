/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:54:05 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

static size_t	find_head(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (in_set(s1[i], set))
		i++;
	return (i);
}

static size_t	calc_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = find_head(s1, set);
	j = (ft_strlen(s1) - 1);
	while (in_set(s1[j], set) && i < j)
		j--;
	len = j - i + 1;
	return (len);
}

static char	*ft_trim(char *dest, const char	*src, size_t i, size_t len)
{
	size_t	indx;

	indx = 0;
	while (indx < len)
		dest[indx++] = src[i++];
	dest[indx] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = calc_len(s1, set);
	if (len > 0)
	{
		str = (char *)malloc(len + 1);
		if (!str)
			return (NULL);
		str = ft_trim(str, s1, find_head(s1, set), len);
		return (str);
	}
	str = malloc(sizeof(*str));
	str[0] = '\0';
	return (str);
}
/*
int	main(void)
{
	const char frase[50] = "                           ";
	const char set[3] = "das";
	char *result;
	
	result = ft_strtrim (frase, set);
	printf ("%s", result);
}
*/
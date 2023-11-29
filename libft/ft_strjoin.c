/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:33:39 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/29 14:58:35 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len_res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_res = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((len_res + 1) + sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, (len_res + 1));
	ft_strlcat(ret, s2, (len_res + 1));
	return (ret);
}
/*
int	main(void)
{
	char const	*frase1;
	char const	*frase2;
	char		*frase_res1;

	frase1 = "Upsieeeeeeeeeeee";
	frase2 = "FART";
	frase_res1 = ft_strjoin(frase1, frase2);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:26 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/09/12 16:29:46 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	closed_quotes(char *str, int i, int len)
{
	char	quo;

	quo = str[i++];
	while (str[i] != quo && i < len)
		i++;
	if (i == len)
		return (0);
	else
		return (i);
}

char	*parse(char *str)
{
	size_t	i;
	size_t	len;
	size_t	q;

	i = 0;
	len = ft_strlen(str);
	q = -1;
	while (i < len)
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			if (!closed_quotes(str, i, len) && i != q)
			{
				printf ("¡You didn't close your quotes you DingDong!\n");
				exit (1);
			}
			q = closed_quotes(str, i, len);
			i = q;
		}
		i++;
	}
	return (str);
}

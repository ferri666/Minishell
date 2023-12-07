/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:50:22 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/15 17:56:40 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

static char	**fill_array(char **store, char const *s, char c)
{
	size_t	len;
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && (flag || *s != c))
			{
				if ((*s == '\"' || *s == '\''))
					changeflag(*s, &flag);
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**commands(char *str, int ncmds)
{
	char	**res;

	if (!str)
		return (NULL);
	res = malloc (sizeof(char *) * (ncmds + 1));
	if (!res)
		return (NULL);
	res = fill_array(res, str, '|');
	return (res);
}

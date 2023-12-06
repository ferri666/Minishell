/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:11:33 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/05 10:16:12 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	**env_cpy(char **env)
{
	char	**copy;
	int		i;

	copy = ft_calloc(ft_strarrlen(env) + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (env[i])
	{
		copy[i] = ft_strdup(env[i]);
		if (!copy[i])
		{
			ft_free_matrix((void **)copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

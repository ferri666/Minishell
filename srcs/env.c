/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:11:33 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/09 16:48:57 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

size_t	equal(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str != '=')
	{
		len++;
		str++;
	}
	return (len);
}

char	**env_cpy(char **env, size_t len)
{
	char	**copy;
	int		i;

	copy = ft_calloc(len + 1, sizeof(char *));
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

int	in_env(char **env, char *str)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], str, equal(str)) == 0)
			return (i);
	}
	return (-1);
}

char	**env_add(char **env, char *str)
{
	char	**newenv;
	size_t	len;

	len = ft_strarrlen(env);
	newenv = env_cpy(env, len + 1);
	if (!newenv)
	{
		ft_error("malloc error. Upsies!");
		return (NULL);
	}
	newenv[len] = ft_strdup(str);
	ft_free_matrix((void **)env);
	return (newenv);
}

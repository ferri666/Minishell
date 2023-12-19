/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:33:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/18 12:09:14 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	change_env(t_minsh *msh, char *new, int i)
{
	char	*sub1;
	char	*sub2;

	sub1 = ft_substr(msh->env[i], eq(msh->env[i]) + 1, ft_strlen(msh->env[i]));
	sub2 = ft_substr(new, eq(new) + 1, ft_strlen(msh->env[i]));
	if (!*sub2 && *sub1)
	{
		free(sub1);
		free(sub2);
		return ;
	}
	free(msh->env[i]);
	msh->env[i] = ft_strdup(new);
	free(sub1);
	free(sub2);
}

void	list_exenv(char **env)
{
	size_t	i;
	char	*sub1;
	char	*sub2;

	i = -1;
	while (env[++i])
	{
		sub1 = ft_substr(env[i], 0, eq(env[i]));
		sub2 = ft_substr(env[i], eq(env[i]) + 1, ft_strlen(env[i]));
		if (*sub2)
			printf("declare -x %s=\"%s\"\n", sub1, sub2);
		else
			printf("declare -x %s\n", sub1);
		free(sub1);
		free(sub2);
	}
}

void	ft_export(t_minsh *msh, t_cmd *c)
{
	int		i;

	i = 0;
	if (c->n_args > 1)
	{
		while (c->args[++i])
		{
			if (!eq(c->args[i]))
			{
				ft_error("export: `");
				ft_putstr_fd(c->args[i], 2);
				ft_putendl_fd("': not a valid identifier", 2);
				msh->exit_code = 1;
				return ;
			}
			else if (in_env(msh->env, c->args[i]) >= 0)
				change_env(msh, c->args[i], in_env(msh->env, c->args[i]));
			else
				msh->env = env_add(msh->env, c->args[i]);
		}
	}
	else
		list_exenv(msh->env);
	msh->exit_code = 0;
}

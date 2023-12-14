/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:33:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/11 18:55:25 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	list_exenv(char **env)
{
	size_t	i;
	char	*sub1;
	char	*sub2;

	i = -1;
	while (env[++i])
	{
		sub1 = ft_substr(env[i], 0, equal(env[i]));
		sub2 = ft_substr(env[i], equal(env[i]) + 1, ft_strlen(env[i]));
		printf("declarse -x %s=\"%s\"\n", sub1, sub2);
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
			if (!equal(c->args[i]))
			{
				ft_error("export: `");
				ft_putstr_fd(c->args[i], 2);
				ft_putendl_fd("': not a valid identifier", 2);
				msh->exit_code = 1;
				return ;
			}
			else if (in_env(msh->env, c->args[i]) >= 0)
				msh->env[in_env(msh->env, c->args[i])] = ft_strdup(c->args[i]);
			else
				msh->env = env_add(msh->env, c->args[i]);
		}
	}
	else
		list_exenv(msh->env);
	msh->exit_code = 0;
}

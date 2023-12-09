/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:33:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/09 16:10:13 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

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
			}
			else if (in_env(msh->env, c->args[i]) >= 0)
				msh->env[in_env(msh->env, c->args[i])] = ft_strdup(c->args[i]);
			else
				msh->env = env_add(msh->env, c->args[i]);
		}
	}
}

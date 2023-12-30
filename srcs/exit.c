/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:36 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/19 12:59:20 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	flee(t_minsh *msh)
{
	int	code;

	byedoc(msh);
	ft_free_matrix((void **)msh->env);
	free(msh->ipath);
	if (msh->n_cmds)
		free_cmds(msh->cmds, msh->n_cmds);
	code = msh->exit_code;
	free(msh);
	exit (code);
}

void	free_cmds(t_cmd **cmds, int ncmds)
{
	int	i;

	i = 0;
	while (i < ncmds)
	{
		if (cmds[i]->input)
			ft_free_matrix((void **)cmds[i]->input);
		if (cmds[i]->output)
			ft_free_matrix((void **)cmds[i]->output);
		if (cmds[i]->args)
			ft_free_matrix((void **)cmds[i]->args);
		if (cmds[i]->command)
		{
			ft_bzero(cmds[i]->command, ft_strlen(cmds[i]->command));
			free(cmds[i]->command);
		}
		if (cmds[i]->in_redir_type)
			ft_free_matrix((void **)cmds[i]->in_redir_type);
		if (cmds[i]->out_redir_type)
			ft_free_matrix((void **)cmds[i]->out_redir_type);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	byedoc(t_minsh *msh)
{
	int	i;

	i = msh->ndocs;
	msh->ndocs = 0;
	while (i--)
	{
		if (msh->filedocs[i])
		{
			unlink(msh->filedocs[i]);
			ft_bzero(msh->filedocs[i], ft_strlen(msh->filedocs[i]));
			free(msh->filedocs[i]);
		}
	}
}

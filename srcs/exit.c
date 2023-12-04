/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:36 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/04 19:08:53 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

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
			free(cmds[i]->command);
		if (cmds[i]->in_redir_type)
			free(cmds[i]->in_redir_type);
		if (cmds[i]->out_redir_type)
			free(cmds[i]->out_redir_type);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
/*
void flee(t_cmd *cmds, char *str)
{
	
}
*/

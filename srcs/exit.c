/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:36 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/31 19:15:15 by ffons-ti         ###   ########.fr       */
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
		ft_free_matrix((void **)cmds[i]->input);
		ft_free_matrix((void **)cmds[i]->output);
		free(cmds[i]->command);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

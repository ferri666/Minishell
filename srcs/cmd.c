/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:58:55 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/04 19:09:25 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

t_cmd	*new_cmd(char *str)
{
	t_cmd	*new;

	new = malloc (sizeof(t_cmd));
	new->input = (char **)ft_calloc(sizeof(char *), n_input(str) + 1);
	new->output = (char **)ft_calloc(sizeof(char *), n_output(str) + 1);
	new->infile = STDIN_FILENO;
	new->outfile = STDIN_FILENO;
	new->args = (char **)ft_calloc(sizeof(char *), ft_cw2(str, ' ') + 1);
	new->in_redir_type = NULL;
	new->out_redir_type = NULL;
	new->next_cmd = NULL;
	new->command = NULL;
	return (new);
}

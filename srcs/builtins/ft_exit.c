/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:14:41 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/07 20:59:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_exit(t_minsh *msh, t_cmd *cmd)
{
	if (cmd->args[1])
		msh->exit_code = ft_atoi(cmd->args[1]);
	else
		msh->exit_code = 0;
	msh->end_prog = 0;
	exit(EXIT_SUCCESS);
}

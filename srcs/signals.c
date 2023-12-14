/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:48:31 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/14 20:36:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void handle_sig(int sig)
{
    if (sig == SIGINT)
    {
	    ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
    }
}

void handle_signals(void)
{
    signal(SIGQUIT, SIG_IGN); // ctrl+/
    signal(SIGINT, handle_sig);
}

void sig_dfl(void)
{
    signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
void sig_ign(void)
{
    signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

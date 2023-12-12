/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:20:20 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/12 20:14:11 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void handle_sigint(int sig)
{
    if (sig == SIGINT)
    {
        printf("hola\n");
        rl_on_new_line();
        rl_replace_line("", 1);
        rl_redisplay();
    }
}
/**/
void handle_cmd_sigint(int sig)
{
    if (sig == SIGINT)
    {
        printf("cmd\n");
        rl_on_new_line();
        rl_replace_line("", 1);
    }
}
/**/
void handle_cmd_signals(void)
{
    signal(SIGQUIT, SIG_IGN); // ctrl+/
    signal(SIGINT, handle_cmd_sigint);
}

void handle_signals(void)
{
    signal(SIGQUIT, SIG_IGN); // ctrl+/
    signal(SIGINT, handle_sigint);
}
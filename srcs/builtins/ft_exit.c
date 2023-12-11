/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:14:41 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/11 15:29:47 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int	n_spaces(const char *str)
{
	int	n;

	n = 0;
	while (is_blank(str[n]))
		n++;
	return (n);
}

/*
Atoi specialized for the minishell.
*/
int	ft_atoi3(const char *str)
{
	int					sign;
	long long unsigned	num;
	int					n;

	sign = 1;
	num = 0;
	n = n_spaces(str);
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign *= -1;
		n++;
	}
	while (ft_isdigit(str[n]))
	{
		num *= 10;
		num += str[n] - '0';
		n++;
	}
	if (n > 19 || str[n] || num > LONG_MAX)
	{
		printf(BRED"MShell: "CRESET"exit: %s is not a valid number\n", str);
		return (255);
	}
	return (sign * num);
}

void	ft_exit(t_minsh *msh, t_cmd *cmd)
{
	if (!cmd->next_cmd)
	{
		if (cmd->n_args > 2)
		{
			ft_error("exit: too many arguments\n");
			msh->exit_code = 1;
		}
		else
		{
			if (cmd->n_args == 2)
				msh->exit_code = ft_atoi3(cmd->args[1]);
			else if (cmd->n_args == 1)
				msh->exit_code = 0;
			msh->end_prog = 0;
			if (msh->exit_code == 69)
				printf(BWHT"'69' Nice... 😏🍆\n");
			printf(BGRN"¡¡Bye, Bye!! 👋😊" BRED "❤️\e[0m\n");
		}
	}
}

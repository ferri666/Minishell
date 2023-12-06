/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:14:41 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/06 15:33:35 by ffons-ti         ###   ########.fr       */
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
		printf(BRED"MShell: exit:"CRESET" %s numeric argument required\n", str);
		return (255);
	}
	return (sign * num);
}

void	ft_exit(t_minsh *msh, t_cmd *cmd)
{
	if (cmd->args[1])
		msh->exit_code = ft_atoi3(cmd->args[1]);
	else
		msh->exit_code = 0;
	msh->end_prog = 0;
}

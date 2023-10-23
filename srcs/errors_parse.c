/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:41:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/23 14:48:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int	check_quotes(char *str)
{
	char	quo;
	int		open;

	open = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '\"'))
		{
			if (!open)
			{
				open = 1;
				quo = *str;
			}
			else if (*str == quo)
				open = 0;
		}
		str++;
	}
	return (open);
}

int	check_pipe(const char *line)
{
	if (line[0] == '|')
	{
		ft_error("MShell: syntax error near '|'\n");
		return (1);
	}
	if (line[ft_strlen(line) - 1] == '|')
	{
		ft_error("MShell: syntax error near '|'\n");
		return (1);
	}
	return (0);
}
int	check_redirections(const char *line)
{
	while (*line)
	{
		if (*line == '>' && *(line + 1) == '<')
		{
			ft_error("MShell: syntax error '><'\n");
			return (1);
		}
		if (*line == '<' && *(line + 1) == '>')
		{
			ft_error("MShell: syntax error '<>'\n");
			return (1);
		}
		if ((*line == '>' && *(line + 1) == '>')
			&& (*(line + 2) == '>' || *(line + 2) == '<'))
		{
			ft_error("MShell: syntax error ;)\n");
			return (1);
		}
		if ((*line == '<' && *(line + 1) == '<')
			&& (*(line + 2) == '>' || *(line + 2) == '<'))
		{
			ft_error("MShell: syntax error ;)\n");
			return (1);
		}
		line++;
	}
	return (0);
}

int	check_errors(char *str)
{
	int	e;

	e = 0;
	e = check_pipe(str);
	if (e)
		return (e);
	e = check_quotes(str);
	if (e)
		return (e);
	e = check_redirections(str);
	if (e)
		return (e);
	return (e);
}

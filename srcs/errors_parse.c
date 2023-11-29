/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:41:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/29 16:19:00 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

static int	check_pipe_bis(const char *line)
{
	while (*line)
	{
		if (*line == '|')
		{
			line++;
			while (*line && is_blank(*line))
				line++;
			if (*line == '\0' || *line == '|')
				return (1);
		}
		line++;
	}
	return (0);
}

static int	check_quotes(char *str)
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
	ft_error ("MShell: ¡You didn't close your quotes you DingDong!\n");
	return (open);
}

static int	check_pipe(const char *line)
{
	if (!line)
		return (1);
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
	if (check_pipe_bis(line))
	{
		ft_error("MShell: syntax error near '|'\n");
		return (1);
	}
	return (0);
}

static int	check_redirections(const char *line)
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
		if (triple_pipe(line))
		{
			ft_error("MShell: syntax error 😉\n");
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

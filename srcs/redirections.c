/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:35:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/24 14:37:25 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*extract_input(char *line)
{
	size_t	n;
	int		flag;
	char	*ret;
	char	*start;

	n = 0;
	flag = 0;
	ret = NULL;
	line++;
	while (*line && is_blank(*line))
		line++;
	start = line;
	while (*line && (flag || (*line != '>' && *line != ' ')))
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		n++;
		line++;
	}
	ret = ft_substr(start, 0, n);
	return (ret);
}

char	*extract_output(char *line)
{
	size_t	n;
	int		flag;
	char	*ret;
	char	*start;

	n = 0;
	flag = 0;
	ret = NULL;
	line++;
	while (*line && is_blank(*line))
		line++;
	start = line;
	while (*line && (flag || (*line != '<' && *line != ' ')))
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		n++;
		line++;
	}
	ret = ft_substr(start, 0, n);
	return (ret);
}

char	*input(char *line)
{
	int		flag;
	char	*inp;

	flag = 0;
	inp = NULL;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '<' && !flag)
		{
			if (*(line + 1) == '<')
				return (ft_strdup("&HEREDOC"));
			else
				inp = extract_input(line);
		}
		line++;
	}
	if (!inp || ft_strlen(inp) == 0)
		return (ft_strdup("&DEFAULT"));
	return (inp);
}

char	*output(char *line, t_cmd *cmd)
{
	int		flag;
	char	*inp;

	flag = 0;
	inp = NULL;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '>' && !flag)
		{
			if (*(line + 1) == '>')
			{
				cmd->append = 1;
				line++;
			}
			inp = extract_output(line);
		}
		line++;
	}
	if (!inp || ft_strlen(inp) == 0)
		return (ft_strdup("&DEFAULT"));
	return (inp);
}


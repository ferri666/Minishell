/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:35:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/02 17:28:48 by ffons-ti         ###   ########.fr       */
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
	while (*line && (flag || (*line != '<' && *line != '>' && *line != ' ')))
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		n++;
		line++;
	}
	ret = ft_substr(start, 0, n);
	if (!ret || n == 0)
		ret = ft_strdup("&STRIDEFAULT");
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
	while (*line && (flag || (*line != '<' && *line != '>' && *line != ' ')))
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		n++;
		line++;
	}
	ret = ft_substr(start, 0, n);
	if (!ret || n == 0)
		ret = ft_strdup("&STRIDEFAULT");
	return (ret);
}

char	**input(char *line)
{
	int		flag;
	char	**inp;
	int		i;

	flag = 0;
	i = 0;
	inp = (char **)malloc (sizeof(char *) * (n_input(line) + 1));
	if (!inp)
		return (NULL);
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '<' && !flag)
		{
			if (*(line + 1) == '<')
				inp[i++] = ft_strdup("&HEREDOC");
			else
				inp[i++] = extract_input(line);
		}
		line++;
	}
	inp[i] = 0;
	return (inp);
}

char	**output(char *line)
{
	int		flag;
	char	**out;
	int		i;

	flag = 0;
	i = 0;
	out = (char **)malloc (sizeof(char *) * (n_output(line) + 1));
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '>' && !flag)
		{
			if (*(line + 1) == '>')
				line++;
			out[i++] = extract_output(line);
		}
		line++;
	}
	out[i] = 0;
	return (out);
}

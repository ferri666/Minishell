/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:14:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/29 17:55:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*quolim(char *st, size_t len)
{
	size_t			j;
	size_t			i;
	char			quo;
	char			*sub_st[5];

	i = 0;
	while (i < len && *(st + i) != '\'' && *(st + i) != '\"')
		i++;
	sub_st[0] = ft_substr(st, 0, i);
	quo = *(st + i);
	i++;
	j = 0;
	while ((i + j) < len && *(st + i + j) != quo)
		j++;
	sub_st[1] = ft_substr(st, i, j);
	sub_st[2] = ft_substr(st, i + j + 1, len - i - j);
	sub_st[3] = ft_strjoin(sub_st[0], sub_st[1]);
	sub_st[4] = ft_strjoin(sub_st[3], sub_st[2]);
	free (st);
	st = ft_strdup(sub_st[4]);
	free_this(sub_st);
	i = 0;
	return (st);
}

int	n_expands(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (line && *line)
	{
		if (*line == '\'')
			changeflag(*line, &flag);
		if (*line == '$' && (!flag || *(line + 1) == ' '))
			n++;
		line++;
	}
	return (n);
}

int	n_quotes(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			changeflag(*line, &flag);
			if (flag == 0)
				n++;
		}
		line++;
	}
	return (n);
}

char	*extract_env(char *env)
{
	while (*env != '=')
		env++;
	env++;
	return (ft_strdup(env));
}

void	free_this(char *this[5])
{
	if (this[0])
		free(this[0]);
	if (this[1])
		free(this[1]);
	if (this[2])
		free(this[2]);
	if (this[3])
		free(this[3]);
	if (this[4])
		free(this[4]);
}

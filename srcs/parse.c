/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:26 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/10 13:53:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	parsecmd(t_cmd *cmds[MAXCMD], char *str, int ncmds)
{
	int	i;

	i = 0;
	while (i < ncmds)
	{
		cmds[i] = malloc(sizeof(t_cmd));
		i++;
	}
}

char	*closed_quotes(char *str)
{
	char	quo;

	quo = *str;
	while (*str != quo && *str)
		str++;
	if (*str == '\0')
	{
		printf ("MShell: 😕 ¡You didn't close your quotes you DingDong!\n");
		return (0);
	}
	else
		return (str);
}

int	count_cmds(char *str)
{
	int		n;

	str = spaces(str);
	if (*str == '\0')
		return (0);
	n = 1;
	while (*str != '\0')
	{
		if (*str == '\"' || *str == '\'')
		{
			if (!closed_quotes(str))
				exit (1);
			str = closed_quotes(str);
		}
		if (*str == '|')
			n++;
		str++;
	}
	return (n);
}

char	*parse(char *str)
{
	t_cmd	cmd[MAXCMD];
	int		ncmds;
	char	*ret;

	ncmds = count_cmds(str);
	printf("\nCommands:%d\n", ncmds);
	if (ncmds > MAXCMD)
	{
		printf("MShell: 👮🛑 Hey par'ner! You put too many commands!\n");
		exit(1);
	}
	if (ncmds == 0)
		return (str);
	if (ncmds > 1)
		parsecmd(&cmd, str, ncmds);
	else
		ret = ft_strtrim(str, " \n\t");
	return (str);
}

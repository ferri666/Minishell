/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:26 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/13 18:56:37 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

t_cmd	**parsecmd(char *str, int ncmds)
{
	int		i;
	t_cmd	**cmds;
	char	**comands;

	i = 0;
	comands = commands(str, ncmds);
	cmds = malloc (sizeof(t_cmd *) * ncmds);
	while (i < ncmds)
	{
		cmds[i] = malloc(sizeof(t_cmd));
		cmds[i]->input = NULL;
		cmds[i]->output = NULL;
		cmds[i]->command = ft_strtrim(comands[i], " \n\t");
		printf("cmd%d:\"%s\"\n", i + 1, cmds[i]->command);
		if (ft_strlen(cmds[i]->command) == 0)
			ft_putstr_fd (BRED "MShell: parse error near '|' \n" RESET, 2);
		i++;
	}
	ft_free_matrix((void **)comands);
	return (cmds);
}

int	count_cmds(char *str)
{
	int		n;
	int		flag;

	flag = 0;
	str = spaces(str);
	n = 0;
	while (*str)
	{
		if (*str != '|')
		{
			while (*str && (flag || *str != '|'))
			{
				if ((*str == '\"' || *str == '\''))
					changeflag(*str, &flag);
				str++;
			}
			n++;
		}
		else
			str++;
	}
	if (flag)
		return (-1);
	return (n);
}

char	*parse(char *str)
{
	t_cmd	**cmd;
	int		ncmds;
	char	*ret;

	ncmds = count_cmds(str);
	if (ncmds < 0)
		printf (BRED "MShell: parse error 😡 ¡Quotes not closed!\n" RESET);
	if (ncmds > MAXCMD)
		printf(BRED "MShell: 👮🛑 Hey par'ner! That's too many commands!\n" RESET);
	else if (ncmds == 0)
		return (str);
	else if (ncmds > 1)
	{
		cmd = parsecmd(str, ncmds);
		free_cmds(cmd, ncmds);
	}
	else
	{
		ret = ft_strtrim(str, " \n\t");
		free(str);
		return (ret);
	}
	return (str);
}

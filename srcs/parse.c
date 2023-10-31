/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:26 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/31 14:42:19 by vpeinado         ###   ########.fr       */
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
	int k = 1;
	i = 0;
	comands = commands(str, ncmds);
	cmds = malloc (sizeof(t_cmd *) * ncmds);
	while (i < ncmds)
	{
		cmds[i] = malloc(sizeof(t_cmd));
		cmds[i]->append = 0;
		cmds[i]->input = input(comands[i]);
		cmds[i]->output = output(comands[i], cmds[i]);
		cmds[i]->command = ft_strtrim(comands[i], " \n\t");
		cmds[i]->arguments = ft_split_args(cmds[i]->command, ' ');
		printf("comando: %s\n", cmds[i]->arguments[0]);
		while (cmds[i]->arguments[k])
		{
			printf("argumento: %s\n", cmds[i]->arguments[k]);
			k++;
		}
		//printf("cmd%d:\"%s\" INPUT:%s OUTPUT:%s\n", i + 1, cmds[i]->command, cmds[i]->input, cmds[i]->output);
		if (ft_strlen(cmds[i]->command) == 0)
			ft_error("MShell: parse error near '|' \n");
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
	return (n);
}

t_cmd	**parse(char *str)
{
	t_cmd	**cmd;
	int		ncmds;

	if (check_errors(str))
		return (NULL);
	ncmds = count_cmds(str);
	if (ncmds > MAXCMD)
		ft_error("MShell: 👮🛑 STOP! That's too many commands!\n");
	else if (ncmds == 0)
		return (NULL);
	else
	{
		cmd = parsecmd(str, ncmds);
		return (cmd);
	}
	return (NULL);
}

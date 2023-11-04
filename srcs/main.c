/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/04 19:28:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	list_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	if (i == 0)
		printf("%s\n", "MShell: We coudn't find any variables. Sorry 🤷");
}

int	main(int argc, char **argv, char **env)
{
	char	*linea;
	t_cmd	**cmd;

	atexit(leaks);
	if (argc != 1)
		printf ("%s\n", argv[1]);
	while (1)
	{
		linea = readline("MShell $~ ");
		cmd = parse(linea);
		if (!cmd)
			break ;
		if (linea)
		{
			add_history(linea);
			if (cmd)
			{
				if (ft_strncmp(cmd[0]->command, "env", 3) == 0)
					list_env(env);
				if (ft_strncmp(cmd[0]->command, "exit", 4) == 0)
					break ;
			}
		}
		free(linea);
	}
	if (cmd)
		free_cmds(cmd, count_cmds(linea));
	free(linea);
	return (0);
}

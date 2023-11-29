/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/29 11:11:30 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	prompt(void)
{
	ft_putendl_fd("***************************", 1);
	ft_putendl_fd("* _____ _____ _       _ _ *", 1);
	ft_putendl_fd("*|     |   __| |_ ___| | |*", 1);
	ft_putendl_fd("*| | | |__   |   | -_| | |*", 1);
	ft_putendl_fd("*|_|_|_|_____|_|_|___|_|_|*", 1);
	ft_putendl_fd("***************************", 1);
}

int	input(char *line)
{
	char	*buf;

	buf = readline("\nMShell $~ ");
	if (!buf)
		return (1);
	if (ft_strlen(buf) > 1000)
	{
		ft_error("MShell: 😱 That's too long!!! I'm not gonna remember that!\n");
		free(buf);
		return (1);
	}
	if (ft_strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(line, buf, ft_strlen(buf) + 1);
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
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
	char	linea[1000];
	t_cmd	**cmd;

	if (argc != 1)
		printf ("%s\n", argv[1]);
	prompt();
	while (1)
	{
		if (input(linea))
			continue ;
		cmd = parse(linea);
		if (cmd)
		{
			main_exec(*cmd, env);
			free_cmds(cmd, count_cmds(linea));
			//leaks();
		}
	}
	if (cmd)
		free_cmds(cmd, count_cmds(linea));
	return (0);
}



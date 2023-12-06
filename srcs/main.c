/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/06 15:42:19 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	logo(void)
{
	ft_putendl_fd(BYEL "***************************", 1);
	ft_putendl_fd("* _____ _____ _       _ _ *", 1);
	ft_putendl_fd("*|     |   __| |_ ___| | |*", 1);
	ft_putendl_fd("*| | | |__   |   | -_| | |*", 1);
	ft_putendl_fd("*|_|_|_|_____|_|_|___|_|_|*", 1);
	ft_putendl_fd("***************************" CRESET, 1);
	ft_putendl_fd("by "BCYN"@ffons-ti "CRESET"& "BCYN"@vpeinado" CRESET, 1);
	ft_putendl_fd("", 1);
}

int	init(t_minsh *min, char **env)
{
	min->cmds = NULL;
	min->env = env_cpy(env);
	min->end_prog = 1;
	min->exit_code = 0;
	return (0);
}

int	input(char *line)
{
	char	*buf;

	if (line)
		ft_bzero(line, 1000);
	rl_on_new_line();
	buf = readline("MShell $~ ");
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
		buf = ft_bzero(buf, ft_strlen(buf));
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	linea[1000];
	t_minsh	*msh;
	int		fd[2];
	int		exit_s;

	if (argc != 1)
		printf ("%s\n", argv[1]);
	logo();
	msh = (t_minsh *)malloc(sizeof(t_minsh) + 1);
	if (init(msh, env))
		exit(1);
	while (msh->end_prog)
	{
		fd[0] = dup(0);
		fd[1] = dup(1);
		if (input(linea))
			continue ;
		if (parse(linea, msh))
			break ;
		if (msh->cmds)
		{
			msh->cmds = expand_all(msh->cmds, count_cmds(linea), env);
			main_exec(msh);
			free_cmds(msh->cmds, count_cmds(linea));
		}
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
	exit_s = msh->exit_code;
	ft_free_matrix((void **)msh->env);
	free(msh);
	exit(exit_s);
}

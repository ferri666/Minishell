/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/30 14:41:51 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	logo(void)
{
	ft_putendl_fd(BYEL "*****************************", 1);
	ft_putendl_fd("** _____ _____ _       _ _ **", 1);
	ft_putendl_fd("**|     |   __| |_ ___| | |**", 1);
	ft_putendl_fd("**| | | |__   |   | -_| | |**", 1);
	ft_putendl_fd("**|_|_|_|_____|_|_|___|_|_|**", 1);
	ft_putendl_fd("*****************************" CRESET, 1);
	ft_putendl_fd("by "BCYN"@vpeinado "CRESET"& "BCYN"@ffons-ti" CRESET, 1);
	ft_putendl_fd("", 1);
}

int	init(t_minsh *min, char **env)
{
	if (!min)
		return (1);
	min->env = env_cpy(env, ft_strarrlen(env));
	if (!min->env)
		return (1);
	min->ipath = ft_calloc(MAXPATHLEN, sizeof(char));
	getcwd(min->ipath, MAXPATHLEN);
	min->cmds = NULL;
	min->end_prog = 1;
	min->n_cmds = 0;
	min->ndocs = 0;
	min->exit_code = 0;
	min->exit_status = 0;
	return (0);
}

void	getlin(char *line, char *buf)
{
	add_history(buf);
	ft_strlcpy(line, buf, ft_strlen(buf) + 1);
	buf = ft_bzero(buf, ft_strlen(buf));
	free(buf);
	buf = NULL;
}

int	input(char *line, t_minsh *msh)
{
	char	*buf;

	if (line)
		ft_bzero(line, 1000);
	buf = readline("\e[1;34mMShell\e[0m $~ ");
	if (buf == NULL)
	{
		printf(BGRN"¡¡Bye, Bye!! 👋😊" BRED "❤️\e[0m\n");
		msh->exit_code = 1;
		flee(msh);
	}
	if (ft_strlen(buf) > 1000)
	{
		ft_error("😱 That's too long!!! I'm not gonna remember that!\n");
		free(buf);
		return (1);
	}
	if (ft_strlen(buf) != 0)
	{
		getlin(line, buf);
		return (0);
	}
	free(buf);
	buf = NULL;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	linea[1000];
	t_minsh	*msh;

	if (argc != 1)
		printf ("%s\n", argv[1]);
	logo();
	msh = (t_minsh *)malloc(sizeof(t_minsh) + 1);
	if (init(msh, env))
		exit(1);
	while (msh->end_prog)
	{
		handle_signals();
		if (input(linea, msh))
			continue ;
		if (parse(linea, msh))
		{
			main_exec(msh);
			free_cmds(msh->cmds, msh->n_cmds);
		}
		msh->n_cmds = 0;
	}
	flee(msh);
}

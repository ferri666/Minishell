/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:06:15 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/19 13:21:14 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*file_doc(t_minsh *msh)
{
	char		*ret;
	char		*i;

	i = ft_itoa(msh->ndocs);
	ret = ft_strjoin("/tmp/.heredoc", i);
	msh->filedocs[msh->ndocs++] = ret;
	free(i);
	return (ret);
}

int	n_expandoc(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (*line)
	{
		if (*line == '$')
			n++;
		line++;
	}
	return (n);
}

char	*expand_doc(char *str, t_minsh *msh)
{
	size_t	i;
	int		n;
	int		flag;
	char	*ret;

	i = 0;
	n = n_expandoc(str);
	flag = 0;
	if (n == 0)
		return (str);
	while (n--)
	{
		while (*(str + i) && *(str + i) != '$')
			i++;
		ret = replace (str, msh, i);
		free (str);
		str = ret;
		i = 0;
	}
	return (str);
}

void	exec_doc(char *endoffile, t_minsh *msh, int fd)
{
	char	*linea;

	while (1)
	{
		clear_history();
		linea = readline(">");
		if (ft_strncmp(linea, endoffile, ft_strlen(endoffile) + 1))
		{
			linea = expand_doc(linea, msh);
			ft_putendl_fd(linea, fd);
			free(linea);
		}
		else
			break ;
	}
	free(linea);
	exit (EXIT_SUCCESS);
}

int	heredoc(char *endoffile, int *count, t_minsh *msh)
{
	int		fd;
	int		pid;
	char	*filedoc;

	filedoc = file_doc(msh);
	if (!filedoc)
	{
		ft_error("error docs!");
		msh->exit_code = 128;
		return (-1);
	}
	fd = open(filedoc, O_RDWR | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (!pid)
		exec_doc(endoffile, msh, fd);
	else
		waitpid (pid, NULL, 0);
	(*count)++;
	close (fd);
	fd = open(filedoc, O_RDONLY);
	return (fd);
}

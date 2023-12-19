/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:42:47 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/18 12:29:26 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*getpath(char **args)
{
	char		*path;
	char		*path2;
	char		*path3;

	path = ft_calloc(MAXPATHLEN, sizeof(char));
	if (*args[1] != '/')
	{
		getcwd(path, MAXPATHLEN);
		path2 = ft_strjoin(path, "/");
		path3 = ft_strjoin(path2, args[1]);
		free(path);
		free(path2);
		return (path3);
	}
	else
		return (ft_strdup(args[1]));
}

void	ft_cd(char **args, t_minsh *msh)
{
	int			errno;
	char		*path;

	path = NULL;
	if (args[1])
		path = getpath(args);
	else
		path = ft_strdup(msh->ipath);
	errno = chdir(path);
	if (errno)
	{
		ft_error("");
		perror("cd");
		ft_putstr_fd(path, 2);
		msh->exit_code = 1;
	}
	else
		msh->exit_code = 0;
	free(path);
}

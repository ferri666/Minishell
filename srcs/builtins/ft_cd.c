/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:42:47 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:49 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_cd(char **args, t_minsh *msh)
{
	char		*path;
	char		*path2;
	char		*path3;
	int			errno;

	if (args)
	{
		path = ft_calloc(MAXPATHLEN, sizeof(char));
		getcwd(path, MAXPATHLEN);
		path2 = ft_strjoin(path, "/");
		path3 = ft_strjoin(path2, args[1]);
		errno = chdir(path3);
		if (errno)
		{
			ft_error("");
			perror("cd");
			msh->exit_code = 1;
		}
		else
			msh->exit_code = 0;
		free(path);
		free(path2);
		free(path3);
	}
}

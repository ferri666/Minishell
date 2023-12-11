/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:06:15 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/11 18:00:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int	heredoc(char *endoffile)
{
	int		fd;
	char	*linea;

	fd = open("._heredoc", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (-1);
	while (1)
	{
		linea = readline(">");
		if (ft_strncmp(linea, endoffile, ft_strlen(endoffile) + 1))
		{
			ft_putstr_fd(linea, fd);
		}
		else
			break ;
	}
	return (fd);
}

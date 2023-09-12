/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/09/12 18:00:00 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef MAXPATHLEN
#  define MAXPATHLEN = 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/param.h>

typedef struct s_line
{
	int		quotes;
	int		redir;
	int		pipes;
	char	**block;

}	t_dline;

char	*parse(char *str);
#endif
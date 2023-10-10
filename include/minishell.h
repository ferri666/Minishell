/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/10 13:14:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAXCMD 50
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

typedef struct s_cmd
{
	char	*input;
	char	*output;
	char	*command;
	char	**arguments;
	int		n_arg;
}	t_cmd;


char	*parse(char *str);
char	*spaces(char *frase);
int		is_blank(int c);

#endif
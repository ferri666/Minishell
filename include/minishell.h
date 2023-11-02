/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/02 17:27:48 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAXCMD 50
# ifndef MAXPATHLEN
#  define MAXPATHLEN 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/param.h>

typedef struct s_cmd
{
	char	**input;
	char	**output;
	char	*command;
	char	**arguments;
	int		n_arg;
	int		append;
}	t_cmd;

/*  parse.c   */
t_cmd	**parse(char *str);
char	*closed_quotes(char *str);
int		count_cmds(char *str);
char	**commands(char *str, int ncmds);

/*  parse_utils.c   */
int		triple_pipe(const char *line);
int		is_redirection(const char *c);
int		is_quote(const char c);
int		n_output(char *line);
int		n_input(char *line);

/*  errors_parse.c   */
int		check_errors(char *str);
int		check_redirections(const char *line);

/*   redirections.c  */
char	**input(char *line);
char	**output(char *line);

/*  utils.c   */
char	*spaces(char *frase);
int		is_blank(int c);
void	changeflag(char c, int *flag);
void	ft_error(char *str);

/*   exit.c  */
void	free_cmds(t_cmd **cmds, int ncmds);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/13 19:45:37 by ffons-ti         ###   ########.fr       */
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
	char	*input;
	char	*output;
	char	*command;
	char	**arguments;
	int		n_arg;
}	t_cmd;

/*  parse.c   */
char	*parse(char *str);
char	*closed_quotes(char *str);
int		count_cmds(char *str);
char	**commands(char *str, int ncmds);

/*  utils.c   */
char	*spaces(char *frase);
int		is_blank(int c);
void	changeflag(char c, int *flag);
void	ft_error(char *str);

/*  errors_parse.c   */
int		check_errors(char *str);

/*   exit.c  */
void	free_cmds(t_cmd **cmds, int ncmds);
#endif
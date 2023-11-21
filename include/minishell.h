/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/21 20:34:32 by ffons-ti         ###   ########.fr       */
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
	char			**input;
	char			**output;
	int				infile;
	int				outfile;
	char			*command;
	char			**args;
	char			*out_redir_type;
	char			*in_redir_type;
	struct s_cmd	*next_cmd;
}	t_cmd;

typedef struct s_minsh
{
	t_cmd	**cmds;
	int		exit_code;
	int		end_prog;
}	t_minsh;


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

/*   redirections.c  */
char	*ex_input(char *str, t_cmd *c, int i);
char	*ex_output(char *str, t_cmd *c, int i);
char	*ex_arg(char *str, t_cmd *c, int i);

/*  utils.c   */
char	*spaces(char *frase);
int		is_blank(int c);
void	changeflag(char c, int *flag);
void	ft_error(char *str);

/*   exit.c  */
void	free_cmds(t_cmd **cmds, int ncmds);

/* split args */
char	**ft_split_args(char const *s, char c);
int		ft_cw2(char const *s, char c);

/* cmd.c */
t_cmd	*new_cmd(char *str);


/*exec + builtin*/
void	main_exec(t_cmd *cmd, char **env);
void	exec_builtin(t_cmd *cmd);
void	execute_command(t_cmd *cmd, int in_fd, int out_fd, char **env);
void	execute_command2(t_cmd *cmd, int in_fd, int out_fd);
int		is_builtin(t_cmd *cmd);
char	*get_env_var(char *var, char **env);
int		is_valid_command_in_path(t_cmd *cmd, char **env);
size_t	ft_strarrlen(char **arr);
void	ft_echo(char **args);
void	ft_exit(t_cmd *cmd);
#endif
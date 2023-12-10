/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:04 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/10 18:18:54 by ffons-ti         ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>

typedef struct s_cmd
{
	char			**input;
	char			**output;
	int				infile;
	int				outfile;
	char			*command;
	char			**args;
	char			**out_redir_type;
	char			**in_redir_type;
	int				n_args;
	struct s_cmd	*next_cmd;
}	t_cmd;

typedef struct s_minsh
{
	t_cmd	**cmds;
	char	**env;
	int		exit_code;
	int		exit_status;
	int		end_prog;
}	t_minsh;

/*   parse.c   */
int		parse(char *str, t_minsh *msh);
int		count_cmds(char *str);

/*   parse_utils.c   */
int		triple_pipe(const char *line);
int		is_redirection(const char *c);
int		is_quote(const char c);
int		n_output(char *line);
int		n_input(char *line);

/*   errors_parse.c   */
int		check_errors(char *str, t_minsh *msh);

/*   redirections.c  */
char	*ex_input(char *str, t_cmd *c, int i);
char	*ex_output(char *str, t_cmd *c, int i);
char	*ex_arg(char *str, t_cmd *c, int i);

/*   expand.c  */
t_cmd	**expand_all(t_cmd **cmd, int n_cmds, t_minsh *msh);

/*   expand_utils.c  */
int		n_expands(char *line);
char	*extract_env(char *env);
int		n_quotes(char *line);
void	free_this(char *this[5]);
char	*quolim(char *st, size_t len);

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
char	**commands(char *str, int ncmds);

/* env.c*/
char	**env_cpy(char **env, size_t len);
char	**env_add(char **env, char *str);
int		in_env(char **env, char *str);
size_t	equal(char *str);

/*exec */
void	main_exec(t_minsh *msh);
void	exec_builtin(t_minsh *msh, t_cmd *cmd);
int		is_builtin1(t_cmd *cmd);
int		is_builtin2(t_cmd *cmd);
char	*get_env_var(char *var, char **env);
int		is_valid_command_in_path(t_cmd *cmd, char **env);
size_t	ft_strarrlen(char **arr);

/*  builtins  */
void	ft_echo(char **args);
void	ft_exit(t_minsh *msh, t_cmd *cmd);
void	ft_pwd(void);
void	ft_cd(char **args);
void	ft_env(t_minsh *msh);
void	ft_export(t_minsh *msh, t_cmd *cmd);
void	ft_unset(t_minsh *msh, t_cmd	*cmd);

/*debug*/
void	leaks(void);

#endif
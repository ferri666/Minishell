/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:22 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/14 20:04:52 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

static void	*child_redir(t_cmd *cmd, int fd[2])
{
	if (cmd->infile != STDIN_FILENO)
	{
		if (dup2(cmd->infile, STDIN_FILENO) == -1)
		{
			ft_error("");
			perror("dup2");
			return (NULL);
		}
		close(cmd->infile);
	}
	if (cmd->outfile != STDOUT_FILENO)
	{
		if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		{
			ft_error("");
			perror("dup2");
			return (NULL);
		}
		close(cmd->outfile);
	}
	else if (cmd->next_cmd && dup2(fd[STDOUT_FILENO], cmd->outfile) == -1)
	{
		ft_error("");
		perror("dup2");
		return (NULL);
	}
	close(fd[STDOUT_FILENO]);
	return ("");
}

void	*child_process(t_cmd *cmd, int fd[2], t_minsh *msh)
{
	child_redir(cmd, fd);
	close(fd[STDIN_FILENO]);
	sig_dfl();
	if (is_builtin2(cmd))
		exec_builtin(msh, cmd);
	else
	{
		if (is_valid_command_in_path(cmd, msh->env))
			msh->exit_code = execve(cmd->command, cmd->args, msh->env);
		else if (access(cmd->command, F_OK) == 0)
			msh->exit_code = execve(cmd->command, cmd->args, msh->env);
		else
		{
			printf(BRED"MShell: "CRESET"%s: command not found\n", cmd->command);
			msh->exit_code = 127;
			exit(127);
		}
		ft_error("");
		perror(cmd->command);
	}
	exit(msh->exit_code);
}

void	exec_fork(t_cmd *cmd, int fd[2], t_minsh *msh)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(fd[STDIN_FILENO]);
		close(fd[STDOUT_FILENO]);
		ft_error("");
		perror("fork");
	}
	else if (!pid)
		child_process(cmd, fd, msh);
}

void	*check_to_fork(t_cmd *cmd, int fd[2], t_minsh *msh)
{
	exec_fork(cmd, fd, msh);
	return ("");
}

static void	*exec_cmd(t_cmd *cmd, t_minsh *msh)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		ft_error("");
		perror("pipe");
		return (NULL);
	}
	if (!check_to_fork(cmd, fd, msh))
		return (NULL);
	close(fd[STDOUT_FILENO]);
	if (cmd->next_cmd && !(cmd->next_cmd->infile))
		cmd->next_cmd->infile = fd[STDIN_FILENO];
	else
		close(fd[STDIN_FILENO]);
	if (cmd->infile > 2)
		close(cmd->infile);
	if (cmd->outfile > 2)
		close(cmd->outfile);
	return (NULL);
}

void open_files(t_cmd *cmd, int *count, t_minsh *msh)
{
	int	i;

	i = 0;
	if (cmd->output)
	{
		while (cmd->output[i])
		{
			if (!ft_strncmp(cmd->out_redir_type[i], ">>", 2))
				cmd->outfile = open(cmd->output[i], O_WRONLY | O_CREAT | O_APPEND, 0666);
			else if (!ft_strncmp(cmd->out_redir_type[i], ">", 1))
				cmd->outfile = open(cmd->output[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (cmd->outfile == -1)
			{
				ft_error("");
				perror("open");
			}
			i++;
		}
	}
	i = 0;
	if (cmd->input)
	{
		while (cmd->input[i])
		{
			if (!ft_strncmp(cmd->in_redir_type[i], "<<", 2))
				cmd->infile = heredoc(cmd->input[i], count, msh);
			else if (!ft_strncmp(cmd->in_redir_type[i], "<", 1))
				cmd->infile = open(cmd->input[i], O_RDONLY);
			if (cmd->infile == -1)
			{
				ft_error("");
				perror("open");
			}
			i++;
		}
	}
}

void main_exec(t_minsh *msh)
{
	t_cmd	*cmd;
	int		cmd_count;
	
	cmd_count = 0;
	if (!msh->cmds)
		return ;
	cmd = msh->cmds[0];
	while (cmd && msh->end_prog)
	{
		if (cmd->input || cmd->output)
			open_files(cmd, &cmd_count, msh);
		if (is_builtin1(cmd))
			exec_builtin(msh, cmd);
		else
		{
			sig_ign();
			exec_cmd(cmd, msh);
			cmd_count++;
		}
		cmd = cmd->next_cmd;
	}
	if (msh->end_prog != 0 && cmd_count)
	{
		while (cmd_count--)
			waitpid(-1, &msh->exit_status, 0);
		if (WIFEXITED(msh->exit_status))
			msh->exit_code = WEXITSTATUS(msh->exit_status);
	}
	byedoc(msh);
}

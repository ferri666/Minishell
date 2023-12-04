/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:22 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/04 18:30:35 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	redirect(t_cmd *cmd, int infile, int outfile)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	if (infile != STDIN_FILENO)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			perror("dup2");
		close(infile);
	}
	if (outfile != STDOUT_FILENO)
	{
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror("dup2");
		close(outfile);
	}
	if (cmd->output)
	{
		while (cmd->output[i])
		{
			if (!ft_strncmp(cmd->out_redir_type, ">>", 2))
				fd = open(cmd->output[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
			else if (!ft_strncmp(cmd->out_redir_type, ">", 1))
				fd = open(cmd->output[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				perror("open");
			if (dup2(fd, STDOUT_FILENO) == -1)
				perror("dup2");
			close(fd);
			i++;
		}
	}
	i = 0;
	if (cmd->input)
	{
		while (cmd->input[i])
		{
			if (!ft_strncmp(cmd->in_redir_type, "<", 1))
				fd = open(cmd->input[i], O_RDONLY);
			else if (!ft_strncmp(cmd->in_redir_type, "<<", 2))
				printf("HEREDoc");
			if (fd == -1)
				perror("open");
			if (dup2(fd, STDIN_FILENO) == -1)
				perror("dup2");
			close(fd);
			i++;
		}
	}
}

void	execute_command(t_cmd *cmd, int infile, int outfile, char **env)
{
	pid_t	pid = fork();
	int status;
	// Crea un proceso hijo y ejecuta el comando utilizando execvp
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0) // Proceso hijo
	{
		redirect(cmd, infile, outfile);
		execve(cmd->command, cmd->args, env); // Ejecuta el comando
		perror("execve");
		exit(1);
	}
	else // Proceso padre
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command %s failed with exit code %d\n", cmd->command, WEXITSTATUS(status));
		}
	}
}

void	main_exec(t_minsh *msh, char **env)
{
	t_cmd	*cmd;
	int		pipefd[2];

	cmd = msh->cmds[0];
	while (cmd)
	{
		if (cmd->next_cmd)
		{
			pipe(pipefd);
			cmd->outfile = pipefd[1];
			((t_cmd *)cmd->next_cmd)->infile = pipefd[0];
		}
		else
			cmd->outfile = STDOUT_FILENO;
		if (is_builtin(cmd))
		{
			exec_builtin(msh, cmd);
		}
		else if (is_valid_command_in_path(cmd, env))
		{
			execute_command(cmd, cmd->infile, cmd->outfile, env);
		}
		else
		{
			if (access(cmd->command, F_OK) == 0)
			{
				execute_command(cmd, cmd->infile, cmd->outfile, env);
			}
			else
			{
				printf("MShell: command not found: %s\n", cmd->command);
				break ;
			}
		}
		close(pipefd[1]);
		cmd->infile = pipefd[0];
		cmd = (t_cmd *)cmd->next_cmd;
	}
}

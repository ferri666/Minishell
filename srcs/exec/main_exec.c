/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:22 by vpeinado          #+#    #+#             */
/*   Updated: 2023/11/16 18:42:33 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void redirect(t_cmd *cmd, int in_fd, int out_fd)
{
    int i;
    int fd;

    fd = 0;
    i = 0;
    if (in_fd != STDIN_FILENO)
    {
        if (dup2(in_fd, STDIN_FILENO) == -1)
            perror("dup2");
        close(in_fd);
    }
    if (out_fd != STDOUT_FILENO)
    {
        if (dup2(out_fd, STDOUT_FILENO) == -1)
            perror("dup2");
        close(out_fd);
    }
    if (cmd->output) // Si hay una redirección de salida, abre el archivo y redirige la salida estándar al archivo
    {
        while (cmd->output[i]) // Iterar sobre cada archivo de salida
        {
            if (!ft_strncmp(cmd->out_redir_type, ">>", 2)) // posible sustituir >> con una constante, buscar
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
            else if(!ft_strncmp(cmd->in_redir_type, "<<", 2))
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

void execute_command(t_cmd *cmd, int in_fd, int out_fd, char **env)
{
    pid_t pid = fork(); // Crea un proceso hijo y ejecuta el comando utilizando execvp
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) // Proceso hijo
    {
        redirect(cmd, in_fd, out_fd);
        execve(cmd->command, cmd->args, env); // Ejecuta el comando
        perror("execve");
        exit(1);
    }
    else // Proceso padre
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "Command %s failed with exit code %d\n", cmd->command, WEXITSTATUS(status));
        }
    }
}

void main_exec(t_cmd *cmd, char **env)
{
    int pipefd[2];

    while (cmd)
    {
        if (cmd->next_cmd)
        {
            pipe(pipefd); // Crea una tubería
            cmd->out_fd = pipefd[1];
            ((t_cmd *)cmd->next_cmd)->in_fd = pipefd[0];
        }
        else
            cmd->out_fd = STDOUT_FILENO;
        if (is_builtin(cmd))
        {
            printf("Es un builtin\n"); // Ejecuta el comando interno
            exec_builtin(cmd);
        }
        else if (is_valid_command_in_path(cmd, env))
        {
            printf("Es un comando válido en el path\n"); // Ejecuta el comando
            execute_command(cmd, cmd->in_fd, cmd->out_fd, env);
        }
        else
        {
            if (access(cmd->command, F_OK) == 0)
            {
                printf("Es un comando válido en el path 2\n"); // Ejecuta el comando
                execute_command(cmd, cmd->in_fd, cmd->out_fd, env);
            }
            else
            {
                printf("no such file or directory: %s", cmd->command);
                break;
            }
        }
        printf("Comando -> %s\n", cmd->command);
        close(pipefd[1]);
        cmd->in_fd = pipefd[0];
        cmd = (t_cmd *)cmd->next_cmd;
    }
}

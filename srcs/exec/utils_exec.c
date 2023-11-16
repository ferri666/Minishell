/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:19 by vpeinado          #+#    #+#             */
/*   Updated: 2023/11/16 18:42:15 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int is_builtin(t_cmd *cmd)
{
    // Comprueba si el comando es un built-in
    if (!ft_strncmp(cmd->command, "echo", 4) 
        || !ft_strncmp(cmd->command, "cd", 2)
        || !ft_strncmp(cmd->command, "pwd", 3)
        || !ft_strncmp(cmd->command, "export", 6)
        || !ft_strncmp(cmd->command, "unset", 5)
        || !ft_strncmp(cmd->command, "env", 3)
        || !ft_strncmp(cmd->command, "exit", 4))
        return (1);
    return (0);
}

void exec_builtin(t_cmd *cmd)
{
    // Ejecuta el comando interno correspondiente
    if (!ft_strncmp(cmd->command, "echo", 4))
        ft_echo(cmd->args);
    else if (!ft_strncmp(cmd->command, "cd", 2))
        printf("builtin");
    else if (!ft_strncmp(cmd->command, "pwd", 3))
        printf("builtin");
    else if (!ft_strncmp(cmd->command, "export", 6))
        printf("builtin");
    else if (!ft_strncmp(cmd->command, "unset", 5))
        printf("builtin");
    else if (!ft_strncmp(cmd->command, "env", 3))
        printf("builtin");
    else if (!ft_strncmp(cmd->command, "exit", 4))
        printf("builtin");
}

char *get_env_var(char *var, char **env)
{
    int i;
    int j;

    i = 0;
    while (env[i])
    {
        j = 0;
        while (env[i][j] == var[j] && env[i][j] != '=')
            j++;
        if (env[i][j] == '=' && var[j] == '\0')
            return (&env[i][j + 1]);
        i++;
    }
    return (NULL);
}

int is_valid_command_in_path(t_cmd *cmd, char **env)
{
    char **path;
    char *tmp;
    int i;

    i = 0;
    // Divide la variable de entorno PATH en una matriz de rutas
    path = ft_split(get_env_var("PATH", env), ':');
    while (path[i])
    {
        // Concatena la ruta y el comando
        tmp = ft_strjoin(path[i], "/");
        tmp = ft_strjoin(tmp, cmd->command);
        // Comprueba si el comando se encuentra en la ruta
        if (access(tmp, F_OK) == 0)
        {
            cmd->command = tmp;
            printf("XXXXXXX%s", tmp);
            return (1);
        }
        free(tmp);
        i++;
    }
    return (0);
}

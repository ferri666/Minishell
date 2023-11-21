/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:19 by vpeinado          #+#    #+#             */
/*   Updated: 2023/11/21 11:29:06 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int	is_builtin(t_cmd *cmd)
{
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

void	exec_builtin(t_cmd *cmd)
{
	// Ejecuta el comando interno correspondiente
	if (!ft_strncmp(cmd->command, "echo", 4))
		ft_echo(cmd->args);
	else if (!ft_strncmp(cmd->command, "cd", 2))
		printf("builtin\n");
	else if (!ft_strncmp(cmd->command, "pwd", 3))
		printf("builtin\n");
	else if (!ft_strncmp(cmd->command, "export", 6))
		printf("builtin\n");
	else if (!ft_strncmp(cmd->command, "unset", 5))
		printf("builtin\n");
	else if (!ft_strncmp(cmd->command, "env", 3))
		printf("builtin\n");
	else if (!ft_strncmp(cmd->command, "exit", 4))
		ft_exit(cmd);
}

char	*get_env_var(char *var, char **env)
{
	int	i;
	int	j;

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

int	is_valid_command_in_path(t_cmd *cmd, char **env)
{
	char	**path;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	path = ft_split(get_env_var("PATH", env), ':');
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd->command);
		if (access(tmp2, F_OK) == 0)
		{
			free (cmd->command);
			cmd->command = ft_strdup(tmp2);
			free(tmp);
			free(tmp2);
			ft_free_matrix((void **)path);
			return (1);
		}
		free(tmp);
		free(tmp2);
		i++;
	}
	ft_free_matrix((void **)path);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/23 14:58:53 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	list_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	if (i == 0)
		printf("%s\n", "We coudn't find any enviroment variables. Sorry 🤷");
}

int	main(int argc, char **argv, char **env)
{
	char	*linea;
	char	*ret;

	atexit(leaks);
	if (argc != 1)
		printf ("%s\n", argv[1]);
	while (1)
	{
		linea = readline("MShell $~ ");
		ret = parse(linea);
		if (ret)
		{
			add_history(ret);
			if (ft_strncmp(ret, "env", 3) == 0)
				list_env(env);
			if (ft_strncmp(ret, "exit", 4) == 0)
				break ;
			free(ret);
		}
		free(linea);
	}
	free(ret);
	free(linea);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/10 13:43:32 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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
		printf("%s\n", "We coudn't find any enviroment. Sorry 🤷");
}

int	main(int argc, char **argv, char **env)
{
	char	*linea;

	atexit(leaks);
	if (argc != 1)
		printf ("%s\n", argv[1]);
	while (1)
	{
		linea = readline("MShell >");
		if (linea)
			add_history(linea);
		linea = parse(linea);
		if (ft_strncmp(linea, "env", 3) == 0)
			list_env(env);
		if (ft_strncmp(linea, "exit", 4) == 0)
			break ;
		free(linea);
	}
	free(linea);
	return (0);
}

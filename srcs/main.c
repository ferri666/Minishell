/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/13 18:22:24 by ffons-ti         ###   ########.fr       */
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

	atexit(leaks);
	if (argc != 1)
		printf ("%s\n", argv[1]);
	while (1)
	{
		linea = readline("MShell $");
		linea = parse(linea);
		if (linea)
			add_history(linea);
		if (ft_strncmp(linea, "env", 3) == 0)
			list_env(env);
		if (ft_strncmp(linea, "exit", 4) == 0)
			break ;
		free(linea);
	}
	free(linea);
	return (0);
}

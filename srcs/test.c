/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/09/12 17:13:33 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

int	main(void)
{
	char	*linea;
	char	*new_line;
	char	*buff;

	buff = malloc(sizeof(char) * MAXPATHLEN);
	if (!buff)
		return (0);
	while (1)
	{
		getcwd(buff, MAXPATHLEN);
		printf("MShell:%s >", buff);
		linea = readline(" ");
		if (!linea)
		{
			free(buff);
			exit(0);
		}
		add_history(linea);
		if (ft_strncmp(linea, "q", 1) == 0 || ft_strncmp(linea, "Q", 1) == 0
			|| ft_strncmp(linea, "exit", 4) == 0)
			break ;
		new_line = parse(linea);
		printf("%s\n", new_line);
		free(linea);
	}
	free(linea);
	free(buff);
	return (0);
}

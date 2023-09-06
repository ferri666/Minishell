/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/09/06 19:25:59 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	main(void)
{
	char	*linea;
	char	*buff;

	buff = malloc(sizeof(char) * MAXPATHLEN);
	if (!buff)
		return (0);
	while (1)
	{

		linea = readline(" ");
		if (!linea)
		{
			free(buff);
			exit(0);
		}
		if (ft_strncmp(linea, "q", 1) == 0 || ft_strncmp(linea, "Q", 1) == 0
			|| ft_strncmp(linea, "exit", 4) == 0)
			break ;
		add_history(linea);
		printf("%s\n", linea);
	}
	free(buff);
	return (0);
}

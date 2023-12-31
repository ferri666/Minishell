/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:16:21 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/11 18:48:54 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_echo(t_minsh *msh, char **args)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "-n", 2) == 0)
		{
			flag = 1;
			i++;
			continue ;
		}
		printf("%s ", args[i]);
		i++;
	}
	if (!flag)
		printf("\n");
	msh->exit_code = 0;
}

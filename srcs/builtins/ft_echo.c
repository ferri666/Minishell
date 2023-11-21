/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:16:21 by vpeinado          #+#    #+#             */
/*   Updated: 2023/11/20 14:43:11 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		printf("%s ", args[i]);
		i++;
	}
	if (ft_strncmp(args[1], "-n", 2) != 0)
		printf("\n");
}

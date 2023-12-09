/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:53:13 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/08 15:00:58 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_env(t_minsh *msh)
{
	size_t	i;

	i = -1;
	while (msh->env[++i])
	{
		if (ft_strchr(msh->env[i], '='))
			printf("%s\n", msh->env[i]);
	}
}

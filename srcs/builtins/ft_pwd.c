/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:51:19 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/05 17:40:30 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void	ft_pwd(void)
{
	char	*cwd;

	cwd = ft_calloc(MAXPATHLEN, sizeof(char));
	getcwd(cwd, MAXPATHLEN);
	printf("%s\n", cwd);
	free(cwd);
}
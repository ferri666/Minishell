/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:51:19 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/07 21:02:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

void ft_pwd(void)
{
    char *pwd;
    pwd = getcwd(NULL, 0);
    printf("%s\n", pwd);
    free(pwd);
	exit(EXIT_SUCCESS);
}

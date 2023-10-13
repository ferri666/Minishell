/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:18:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/13 17:40:05 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*spaces(char *frase)
{
	while (is_blank(*frase) && *frase)
		frase++;
	return (frase);
}

int	is_blank(int c)
{
	if (c == 0)
		return (1);
	if (c == ' ' || c == '\n' || c == '\t')
		return (c);
	return (0);
}

void	changeflag(char c, int *flag)
{
	char static	q = 0;

	if (*flag == 0)
	{
		*flag = 1;
		q = c;
	}
	else if (c == q)
		*flag = 0;
}

char	*closed_quotes(char *str)
{
	char	quo;

	quo = *str;
	while (*str != quo && *str)
		str++;
	if (*str == '\0')
	{
		printf ("MShell: 😕 ¡You didn't close your quotes you DingDong!\n");
		return (0);
	}
	else
		return (str);
}
/*
int	main(void)
{
	char	*frase = "      hola         ";
	char	*hello = spaces(frase);

	printf("%s$\n", frase);
	printf("%s$\n", spaces(hello + 4));
	printf("%s$\n", hello);
	printf("%s$\n", frase);
}
*/
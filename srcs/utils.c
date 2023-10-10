/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:18:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/10 12:57:20 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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
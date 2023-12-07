/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:18:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/05 11:23:31 by ffons-ti         ###   ########.fr       */
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

size_t	ft_strarrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	ft_error(char *str)
{
	ft_putstr_fd(BRED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
}

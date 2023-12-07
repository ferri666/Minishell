/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:10:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/02/22 12:15:49 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_chr(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

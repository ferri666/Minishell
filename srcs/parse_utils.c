/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:59:18 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/10/23 17:21:50 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

int	triple_pipe(const char *line)
{
	if ((*line == '>' && *(line + 1) == '>')
		&& (*(line + 2) == '>' || *(line + 2) == '<'))
		return (1);
	if ((*line == '<' && *(line + 1) == '<')
		&& (*(line + 2) == '>' || *(line + 2) == '<'))
		return (1);
	return (0);
}

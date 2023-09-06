/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:38:01 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/14 12:17:27 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlines(char *file)
{
	int		lines;
	int		fd;
	char	*line;

	lines = 0;
	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (lines);
	line = get_next_line(fd);
	if (line)
		lines++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			lines++;
	}
	close (fd);
	return (lines);
}

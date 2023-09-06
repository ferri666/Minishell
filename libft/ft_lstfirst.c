/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:30:51 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/10 11:31:02 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstfirst(t_dlist *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->before == NULL)
			return (lst);
		lst = lst->before;
	}
	return (NULL);
}

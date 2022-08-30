/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:50:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/15 15:56:17 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*actual;

	if (lst)
	{
		actual = *lst;
		*lst = NULL;
		while (actual)
		{
			next = actual->next;
			ft_lstdelone(actual, del);
			actual = next;
		}
	}
}

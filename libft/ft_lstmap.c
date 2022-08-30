/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:51:39 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/15 10:51:41 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (del)(void *))
{
	t_list	*lstnew;
	t_list	*elemnew;

	if (!lst || !f)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		elemnew = ft_lstnew(f(lst->content));
		if (! elemnew)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, elemnew);
		lst = lst->next;
	}
	return (lstnew);
}

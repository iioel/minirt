/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:19:23 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*parsing(char *file)
{
	int		fd;
	t_list	*lst;
	char	*str;
	void	*tmp;

	str = NULL;
	lst = ft_lstnew(NULL);
	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		tmp = new_object(str);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(tmp));
		str = get_next_line(fd);
	}
	close(fd);
	tmp = lst->next;
	free(lst);
	lst = tmp;
	return (lst);
}

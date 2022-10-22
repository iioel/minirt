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

void	pars_list(int fd, t_list *tmp, t_list *lst)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		tmp = new_object(str);
		free(str);
		if (!tmp)
			return ;
		ft_lstadd_back(&lst, ft_lstnew(tmp));
		str = get_next_line(fd);
	}
	return ;
}

t_list	*parsing(char *file)
{
	int		fd;
	t_list	*lst;
	char	*str;
	void	*tmp;

	str = NULL;
	lst = ft_lstnew(NULL);
	tmp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("minirt: ");
		exit(1);
	}
	pars_list(fd, tmp, lst);
	close(fd);
	tmp = lst->next;
	free(lst);
	lst = tmp;
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 16:23:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*new_object(char *str)
{
	
}

t_list	*parsing(char *file)
{
	int		fd;
	t_list	*lst;
	char	*str;

	str = NULL;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{

		str = get_next_line(fd);
	}
}
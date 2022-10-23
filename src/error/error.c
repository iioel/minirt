/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 18:29:10 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>

int	print_error(char *str)
{
	if (!str)
		return (0);
	write(2, str, ft_strlen(str));
	return (1);
}

void	error_message(int i, t_type t)
{
	char	*tmp;

	print_error("minirt: bad config ");
	tmp = get_strtype(t);
	print_error(tmp);
	free(tmp);
	print_error(" config_file line: ");
	tmp = ft_itoa(i + 1);
	print_error(tmp);
	free(tmp);
	print_error("\n");
}

void	error(t_window *w)
{
	int		i;
	int		flag;
	t_list	*l;

	i = 0;
	l = w->objs;
	flag = 0;
	while (l)
	{
		if (((t_object *)l->content)->type == camera)
			flag = 1;
		if (((t_object *)l->content)->error)
		{	
			if (((t_object *)l->content)->error(l->content))
			{
				error_message(i, ((t_object *)l->content)->type);
				clean_win(w);
				exit(1);
			}
		}
		l = l->next;
		i++;
	}
	if (!flag)
		exit(print_error("minirt: there is no camera in your file\n"));
}
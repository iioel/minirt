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

void	exit_print(t_window *w, char *str)
{
	clean_win(w);
	exit(print_error(str));
}

void	check_once(t_window *w, t_list *l)
{
	static int	n_cam = 0;
	static int	n_amb = 0;

	if (((t_object *)l->content)->type == camera)
		n_cam++;
	else if (((t_object *)l->content)->type == ambient)
		n_amb++;
	if (!l->next)
	{
		if (n_cam == 0)
			exit_print(w, "minirt: there is no camera in your file\n");
		else if (n_cam > 1)
			exit_print(w,
				"minirt: there is more than one camera in your file\n");
		if (n_amb > 1)
			exit_print(w,
				"minirt: there is more than one ambient light in your file\n");
	}
}

void	error(t_window *w)
{
	int		i;
	t_list	*l;

	i = 0;
	l = w->objs;
	while (l)
	{
		check_once(w, l);
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:35:23 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/06 14:42:04 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_window	*save_window(t_window *w)
{
	static t_window	*win = NULL;

	if (w != NULL)
		win = w;
	return (win);
}

t_window	*create_win(int width, double a_r, char *name)
{
	t_window	*w;

	w = ft_calloc(1, sizeof(t_window));
	if (! w)
		return (NULL);
	w->aspect_ratio = a_r;
	w->width = width;
	w->height = (int)(w->width / w->aspect_ratio);
	w->mlx = mlx_init();
	if (! w->mlx)
		return (clean(w));
	w->w = mlx_new_window(w->mlx, w->width, w->height, name);
	if (! w->w)
		return (clean(w));
	return (w);
}

int	clean_win(t_window *w)
{	
	mlx_destroy_window(w->mlx, w->w);
	free(w);
	return (0);
}

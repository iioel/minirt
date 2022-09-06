/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:02:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/20 14:52:30 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "vector.h"
#include "camera.h"

t_camera	*get_camera(t_list *lst)
{
	while (lst)
	{
		if (((t_object *)lst->content)->type == camera)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}

void	camera_init(t_camera *c, double a_r)
{
	c->viewport_height = 2.;
	c->viewport_width = a_r * c->viewport_height;
	c->focal_length = tan((c->fov * M_PI / 180) / 2.);
	camera_upd_view(c);
}

void	camera_upd_view(t_camera *c)
{
	t_vector	tmp;

	c->horizontal = vec_init(c->viewport_width, 0, 0);
	c->vertical = vec_add(vec_init(0, c->viewport_height, 0), c->dir);
	tmp = vec_sub(c->origin, vec_div(c->horizontal, 2));
	tmp = vec_add(tmp, vec_div(c->vertical, 2));
	c->upper_left_corner = vec_sub(tmp, vec_init(0, 0, c->focal_length));
}

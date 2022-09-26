/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:02:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/26 19:11:59 by yoel             ###   ########.fr       */
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
	double	f;

	f = tan((c->fov * M_PI / 180));
	c->viewport_height = 2.;
	c->viewport_width = a_r * c->viewport_height;
	c->focal_length = 1. / f;
	printf("Fov: %d\nfocal_lgth: %f\n", c->fov, c->focal_length);
	camera_upd_view(c);
}

void	camera_upd_view(t_camera *c)
{
	t_vector	tmp;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	w = vec_unit(c->dir);
	u = vec_unit(vec_cross(vec_init(0., 1., 0.), w));
	v = vec_cross(w, u);
	c->horizontal = vec_mul_nb(u, c->viewport_width);
	c->vertical = vec_mul_nb(v, c->viewport_height);
	tmp = vec_sub(c->origin, vec_div(c->horizontal, 2));
	tmp = vec_add(tmp, vec_div(c->vertical, 2));
	c->upper_left_corner = vec_sub(tmp, vec_mul_nb(c->dir, c->focal_length));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:02:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:40:10 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "obj/camera.h"
#include "obj/object.h"
#include "obj/sphere.h"
#include "vector.h"

void	*new_camera(char *str)
{
	t_camera	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_camera));
	if (!c)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %i", &stype, &(c->origin.x),
		&(c->origin.y), &(c->origin.z), &(c->dir.x), &(c->dir.y),
		&(c->dir.z), &(c->fov));
	c->intercept = NULL;
	c->type = get_type(stype);
	c->error = &error_camera;
	free(stype);
	return (c);
}

void	camera_init(t_camera *c, double a_r)
{
	double	f;

	f = tan((c->fov * M_PI / 180) / 2);
	c->viewport_height = 2.;
	c->viewport_width = a_r * c->viewport_height;
	c->focal_length = 1. / f;
	camera_upd_view(c);
}

void	*new_camera_object(t_object *obj)
{
	t_camera	*c;
	int			add;

	c = ft_calloc(1, sizeof(t_camera));
	if (!c)
		return (NULL);
	c->type = camera;
	if (obj->type == sphere || obj->type == cylinder)
		add = ((t_sphere *)obj)->diameter + 2;
	else
		add = 5;
	c->origin.x = ((t_sphere *)obj)->point.x + add;
	c->origin.y = ((t_sphere *)obj)->point.y + add;
	c->origin.z = ((t_sphere *)obj)->point.z;
	c->dir.x = -1;
	c->dir.y = -1;
	c->dir.z = 0;
	c->fov = 70;
	camera_init(c, 16. / 9.);
	return (c);
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
	c->upper_left_corner = vec_add(tmp, vec_mul_nb(c->dir, c->focal_length));
}

int	free_camera(t_camera *cam)
{
	if (cam == NULL)
		return (1);
	free(cam);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 17:20:36 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	error_sphere(t_object *o)
{
	t_sphere	*s;

	s = (t_sphere *)o;
	if (s->type != sphere)
		return (1);
	if (s->intercept == NULL)
		return (1);
	if (s->color.r < 0 || s->color.g < 0 || s->color.b < 0)
		return (1);
	if (s->diameter <= 0)
		return (1);
	return (0);
}

int	error_ambient(t_object *o)
{
	t_ambient	*a;

	a = (t_ambient *)o;
	if (a->type != ambient)
		return (1);
	if (a->intercept != NULL)
		return (1);
	if (a->color.r < 0 || a->color.g < 0 || a->color.b < 0)
		return (1);
	if (a->lighting <= 0)
		return (1);
	return (0);
}

int	error_camera(t_object *o)
{
	t_camera	*c;

	c = (t_camera *)o;
	if (c->type != camera)
		return (1);
	if (c->intercept != NULL)
		return (1);
	if (c->fov <= 0)
		return (1);
	return (0);
}

int	error_cylinder(t_object *o)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)o;
	if (cy->type != cylinder)
		return (1);
	if (cy->intercept == NULL)
		return (1);
	if (cy->color.r < 0 || cy->color.g < 0 || cy->color.b < 0)
		return (1);
	if (cy->diameter <= 0 || cy->height <= 0)
		return (1);
	return (0);
}

int	error_light(t_object *o)
{
	t_light	*l;

	l = (t_light *)o;
	if (l->type != light)
		return (1);
	if (l->intercept != NULL)
		return (1);
	if (l->color.r < 0 || l->color.g < 0 || l->color.b < 0)
		return (1);
	if (l->brightness <= 0)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:17:35 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:49:48 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"
#include "ft_math.h"
#include "rotate.h"

void	*new_cylinder(char *str)
{
	t_cylinder	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_cylinder));
	if (!c)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %f %f #%2x%2x%2x", &stype,
		&(c->point.x), &(c->point.y), &(c->point.z), &(c->vect.x),
		&(c->vect.y), &(c->vect.z), &(c->diameter), &(c->height),
		&(c->color.r), &(c->color.g), &(c->color.b));
	c->type = get_type(stype);
	c->intercept = &cylinder_inter;
	c->diam_half = c->diameter / 2.;
	c->diam_half_pow = c->diam_half * c->diam_half;
	c->height_half = c->height / 2.;
	c->half_sqrt = sqrt(c->diam_half_pow + (c->height_half * c->height_half));
	c->error = &error_cylinder;
	free(stype);
	return (c);
}

double	cylinder_get_len(double eq[4], t_cylinder *c, t_ray *r)
{
	t_point		p;
	t_vector	len;
	double		t1;
	double		t2;
	double		max;

	t1 = -1.;
	if (eq[DESC] == 0.)
		t1 = -(eq[B] / (2. * eq[A]));
	else if (eq[DESC] > 0.)
	{
		t1 = (-eq[B] + sqrt(eq[DESC])) / (2. * eq[A]);
		t2 = (-eq[B] - sqrt(eq[DESC])) / (2. * eq[A]);
		if (t2 >= 0. && t2 < t1)
			t1 = t2;
	}
	max = c->half_sqrt;
	p = vec_add(r->origin, vec_mul_nb(r->dir, t1));
	len = vec_sub(p, c->point);
	if (vec_length(len) > max)
		return (-1);
	return (t1);
}

double	cylinder_inter(t_object *o, t_ray *r, t_vector *n)
{
	t_ray		rb;
	t_vector	oc;
	t_cylinder	*c;
	double		eq[4];
	double		t[2];

	t[0] = -1.;
	c = (t_cylinder *)o;
	rb.origin = r->origin;
	rb.dir = vec_cross(r->dir, c->vect);
	oc = vec_sub(r->origin, c->point);
	eq[A] = vec_dot(rb.dir, rb.dir);
	eq[B] = 2. * vec_dot(rb.dir, vec_cross(oc, c->vect));
	eq[C] = vec_dot(vec_cross(oc, c->vect), vec_cross(oc, c->vect))
		- c->diam_half_pow;
	eq[DESC] = (eq[B] * eq[B]) - 4. * eq[A] * eq[C];
	if (eq[DESC] >= 0.)
		t[0] = cylinder_get_len(eq, c, r);
	t[1] = cylinder_caps_inter(c, r, n);
	if ((t[0] >= 0. && t[0] < t[1]) || t[1] < 0.)
		*n = cylinder_get_normal(o, vec_add(r->origin,
					vec_mul_nb(r->dir, t[0])));
	if ((t[0] >= 0. && t[0] < t[1]) || t[1] < 0.)
		return (t[0]);
	return (t[1]);
}

t_vector	cylinder_get_normal(t_object *o, t_point p)
{
	t_cylinder	*c;
	t_point		pbis;
	t_point		cpoint;
	double		ax;
	double		ay;

	c = (t_cylinder *)o;
	c->vect = vec_unit(c->vect);
	ax = atan(c->vect.z / c->vect.x) * 180. / M_PI;
	if (c->vect.x < 0.)
		ax += 180.;
	ay = acos(c->vect.y / 1.) * 180. / M_PI;
	if (c->vect.y == 1. || c->vect.y == -1.)
		ax = 0.;
	if (c->vect.y == 1. || c->vect.y == -1.)
		ay = 0.;
	pbis = vec_sub(p, c->point);
	pbis = rotate(pbis, 0., ax, ay);
	pbis = vec_add(pbis, c->point);
	cpoint = vec_dup(c->point);
	cpoint.y = pbis.y;
	cpoint = vec_sub(cpoint, c->point);
	cpoint = rev_rotate(cpoint, 0., -ax, -ay);
	cpoint = vec_add(cpoint, c->point);
	return (vec_unit(vec_sub(p, cpoint)));
}

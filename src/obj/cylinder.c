/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:17:35 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 06:32:08 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"
#include "ft_math.h"

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
	c->get_normal = &cylinder_get_normal;
	free(stype);
	return (c);
}

double	cylinder_inter(t_object *o, t_ray *r)
{
//	t_vector	tmp;
//	t_vector	w;
//	t_vector	u;
//	t_vector	v;
//
//	w = vec_unit(c->vect);
//	u = vec_unit(vec_cross(vec_init(0., 1., 0.), w));
//	v = vec_unit(vec_cross(w, u));
//	tmp = 
//	c->x = vec_mul_nb(u, c->viewport_width);
//	c->z = vec_mul_nb(v, c->viewport_height);
//	tmp = vec_sub(c->origin, vec_div(c->horizontal, 2));
//	tmp = vec_add(tmp, vec_div(c->vertical, 2));
//	c->upper_left_corner = vec_add(tmp, vec_mul_nb(c->dir, c->focal_length));
	t_vector	oc;
	t_cylinder	*c;
	double		eq[4];
	double		t1;
	double		t2;

	t1 = -1;
	c = (t_cylinder *)o;
	oc = vec_sub(r->origin, c->point);
	eq[A] = r->dir.x * r->dir.x + r->dir.y * r->dir.y;
	eq[B] = 2. * (oc.x * r->dir.x + oc.y * r->dir.y);
	eq[C] = (oc.x * oc.x + oc.y * oc.y - c->diameter);
	eq[DESC] = (eq[B] * eq[B]) - 4 * eq[A] * eq[C];
	if (eq[DESC] == 0)
		t1 = -(eq[B] / (2 * eq[A]));
	else if (eq[DESC] > 0)
	{
		t1 = (-eq[B] + sqrt(eq[DESC])) / (2 * eq[A]);
		t2 = (-eq[B] - sqrt(eq[DESC])) / (2 * eq[A]);
		if (t2 >= 0 && t2 < t1)
			return (t2);
	}
	return (t1);
}

t_vector	cylinder_get_normal(t_object *o, t_point p)
{
	t_cylinder	*c;

	c = (t_cylinder *)o;
	return (vec_init(p.x - c->point.x, p.y - c->point.y, c->point.z));
}


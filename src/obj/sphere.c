/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:14:52 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 14:51:24 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/sphere.h"
#include "ft_math.h"

void	*new_sphere(char *str)
{
	t_sphere	*s;
	char		*stype;

	s = ft_calloc(1, sizeof(t_sphere));
	if (!s)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f #%2x%2x%2x", &stype, &(s->point.x),
		&(s->point.y), &(s->point.z), &(s->diameter), &(s->color.r),
		&(s->color.g), &(s->color.b));
	s->type = get_type(stype);
	s->intercept = &sphere_inter;
	s->get_normal = &sphere_get_normal;
	s->error = &error_sphere;
	free(stype);
	return (s);
}

double	sphere_inter(t_object *o, t_ray *r, t_vector *n)
{
	t_vector	oc;
	t_sphere	*sp;
	double		eq[4];
	double		t1;
	double		t2;

	t1 = -1;
	sp = (t_sphere *)o;
	oc = vec_sub(r->origin, sp->point);
	eq[A] = vec_dot(r->dir, r->dir);
	eq[B] = 2.0 * vec_dot(oc, r->dir);
	eq[C] = vec_dot(oc, oc) - ((sp->diameter / 2) * sp->diameter / 2);
	eq[DESC] = (eq[B] * eq[B]) - 4 * eq[A] * eq[C];
	if (eq[DESC] == 0)
		t1 = -(eq[B] / (2 * eq[A]));
	else if (eq[DESC] > 0)
	{
		t1 = (-eq[B] + sqrt(eq[DESC])) / (2 * eq[A]);
		t2 = (-eq[B] - sqrt(eq[DESC])) / (2 * eq[A]);
		if (t2 >= 0 && t2 < t1)
			t1 = t2;
	}
	*n = sphere_get_normal(o, vec_add(r->origin, vec_mul_nb(r->dir, t1)));
	return (t1);
}

t_vector	sphere_get_normal(t_object *o, t_point p)
{
	t_sphere	*sp;

	sp = (t_sphere *)o;
	return (vec_sub(p, sp->point));
}

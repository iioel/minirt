/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:14:52 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 16:09:22 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/sphere.h"

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
	free(stype);
	return (s);
}

double	sphere_inter(t_object *o, t_ray *r)
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
			return (t2);
	}
	return (t1);
}

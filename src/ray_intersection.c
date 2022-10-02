/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/02 15:30:38 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "float.h"

double	plane_inter(t_object *o, t_ray *r)
{
	t_plane		*pl;
	double		t;
	t_vector	d;
	t_vector	e;

	pl = (t_plane *)o;
	d = vec_sub(vec_mul(pl->vect, pl->point), vec_mul(pl->vect, r->origin));
	e = vec_mul(pl->vect, r->dir);
	t = (d.x + d.y + d.z) / (e.x + e.y + e.z);
	return (t);
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
	eq[DESC] = pow(eq[B], 2) - 4 * eq[A] * eq[C];
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

int	get_ray_color(t_ray ray, t_color *color, t_list *lst)
{
	double		res;
	double		nearest;
	t_object	*nearest_obj;

	nearest = DBL_MAX;
	nearest_obj = NULL;
	while (lst)
	{
		if (((t_object *)lst->content)->intercept)
		{
			res = ((t_object *)lst->content)->intercept((lst->content), &ray);
			if ((nearest_obj == NULL || res < nearest) && res >= 0)
			{
				nearest = res;
				nearest_obj = (t_object *)lst->content;
			}
		}
		lst = lst->next;
	}
	if (nearest_obj)
		*color = nearest_obj->color;
	return (nearest_obj == NULL);
}

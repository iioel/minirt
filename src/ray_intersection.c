/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/27 16:50:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	plane_inter(t_object *o, t_ray *r)
{
	t_plane	*pl;
	double		t;
	t_vector	d;
	t_vector	D;

	pl = (t_plane *)o;
	d = vec_sub(vec_mul(pl->vect, pl->point), vec_mul(pl->vect, r->origin));
	D = vec_mul(pl->vect, r->dir);
	t = (d.x + d.y + d.z) / (D.x + D.y + D.z);

	return (t > 0.);
}

int	sphere_inter(t_object *o, t_ray *r)
{
	t_vector	oc;
	t_sphere	*sp;
	double		b;
	double		c;
	double		disc;

	sp = (t_sphere *)o;
	oc = vec_sub(r->origin, sp->point);
	b = 2.0 * vec_dot(oc, r->dir);
	c = vec_dot(oc, oc) - ((sp->diameter / 2) * sp->diameter / 2);
	disc = b * b - 4 * vec_dot(r->dir, r->dir) * c;
	//printf("%f %f %f\n", r->dir.x, r->dir.y, r->dir.z);
	return (disc > 0);
}

int	get_ray_color(t_ray ray, t_color *color, t_list *lst)
{
	while (lst)
	{
		if (((t_object *)lst->content)->intercept
			&& ((t_object *)lst->content)->intercept((lst->content), &ray))
		{
			*color = ((t_object *)lst->content)->color;
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

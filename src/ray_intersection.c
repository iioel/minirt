/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 17:27:29 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



int	plane_inter(t_object *o, t_ray *r)
{
	t_plane		pl;

	pl = (t_plane *)o;
	return (vec_dot(r->dir, pl->vect) != 0);
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
	return (disc > 0);
}

int	ray_color(void *this, t_color *color, t_list *lst)
{
	while (lst)
	{
		if (((t_object *)lst->content)->intercept((lst->content), this))
		{
			*color = ((t_object *)lst->content)->color;
			return (0);
		}	
		lst = lst->next;
	}
	return (1);
}

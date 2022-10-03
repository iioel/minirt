/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:18:33 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 16:09:13 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/plane.h"

void	*new_plane(char *str)
{
	t_plane	*p;
	char	*stype;

	p = ft_calloc(1, sizeof(t_plane));
	if (!p)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f #%2x%2x%2x", &stype, &(p->point.x),
		&(p->point.y), &(p->point.z), &(p->vect.x), &(p->vect.y),
		&(p->vect.z), &(p->color.r), &(p->color.g), &(p->color.b));
	p->type = get_type(stype);
	p->intercept = &plane_inter;
	free(stype);
	return (p);
}

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

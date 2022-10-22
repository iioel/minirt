/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:18:33 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 14:49:38 by ycornamu         ###   ########.fr       */
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
	p->get_normal = &plane_get_normal;
	p->error = &error_plane;
	free(stype);
	return (p);
}

double	plane_inter(t_object *o, t_ray *r, t_vector *n)
{
	t_plane		*pl;
	double		t;
	t_vector	d;
	t_vector	e;

	pl = (t_plane *)o;
	d = vec_sub(vec_mul(pl->vect, pl->point), vec_mul(pl->vect, r->origin));
	e = vec_mul(pl->vect, r->dir);
	t = (d.x + d.y + d.z) / (e.x + e.y + e.z);
	*n = plane_get_normal(o, vec_init(0, 0, 0));
	return (t);
}

t_vector	plane_get_normal(t_object *o, t_point p)
{
	t_plane		*pl;

	(void)p;
	pl = (t_plane *)o;
	return (pl->vect);
}

int	error_plane(t_object *o)
{
	t_plane	*pl;

	pl = (t_plane *)o;
	if (pl->type != plane)
		return (1);
	if (pl->intercept == NULL || pl->get_normal == NULL)
		return (1);
	if (pl->color.r < 0 || pl->color.g < 0 || pl->color.b < 0)
		return (1);
	return (0);
}

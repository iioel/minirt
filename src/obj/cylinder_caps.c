/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:45:23 by yoel              #+#    #+#             */
/*   Updated: 2022/10/17 16:32:07 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"

double	cylinder_caps_inter(t_cylinder *c, t_ray *r)
{
	double	t;
	double	d_len;
	double	d_len_max;

	d_len_max = sqrt((c->height / 2) * (c->height / 2)
			+ (c->diameter / 2) * (c->diameter / 2));
	t = cylinder_caps_inter_2(c, r, 1);
	d_len = vec_length(vec_sub(vec_add(r->origin, vec_mul_nb(r->dir, t)),
				c->point));
	if (d_len > d_len_max)
	{
		t = cylinder_caps_inter_2(c, r, -1);
		d_len = vec_length(vec_sub(vec_add(r->origin, vec_mul_nb(r->dir, t)),
					c->point));
		if (d_len > d_len_max)
			return (-1);
	}
	return (t);
}

double	cylinder_caps_inter_2(t_cylinder *c, t_ray *r, int up_down)
{
	double		t;
	t_vector	d;
	t_vector	e;
	t_vector	tmp;

	tmp = vec_add(c->point, vec_mul_nb(c->vect, up_down * c->height / 2));
	d = vec_sub(vec_mul(c->vect, tmp), vec_mul(c->vect, r->origin));
	e = vec_mul(c->vect, r->dir);
	t = (d.x + d.y + d.z) / (e.x + e.y + e.z);
	return (t);
}

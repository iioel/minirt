/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:45:23 by yoel              #+#    #+#             */
/*   Updated: 2022/10/18 09:00:46 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"

double	cylinder_caps_inter(t_cylinder *c, t_ray *r)
{
	double	t1;
	double	t2;
	double	d1_len;
	double	d2_len;
	double	d_len_max;

	d_len_max = sqrt((c->height / 2) * (c->height / 2)
			+ (c->diameter / 2) * (c->diameter / 2));
	t1 = cylinder_caps_inter_2(c, r, 1);
	t2 = cylinder_caps_inter_2(c, r, -1);
	d1_len = vec_length(vec_sub(vec_add(r->origin, vec_mul_nb(r->dir, t1)),
				c->point));
	d2_len = vec_length(vec_sub(vec_add(r->origin, vec_mul_nb(r->dir, t2)),
				c->point));
	if (d1_len <= d_len_max && t1 >= 0)
	{
		if (d2_len <= d_len_max && t2 >= 0 && t2 < t1)
			return (t2);
		return (t1);
	}
	else if (d2_len <= d_len_max && t2 >= 0)
		return (t2);
	return (-1);
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

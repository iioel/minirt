/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:57:20 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/02 23:12:31 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_color	compute_lights(t_color c, t_object *o, t_ray ray, double d, t_list *lst)
{
	t_point		hit;
	t_vector	n;
	t_light		*l;
	double		r;
	t_color		out;
	t_vector	light_ray_dir;

	out = c;
	hit = vec_add(ray.origin, vec_mul_nb(ray.dir, d));
	//n = o->get_normal(o, hit);
	n = vec_sub(hit, ((t_sphere *)o)->point);
	n = vec_unit(n);
	while (lst)
	{
		if (((t_object *)lst->content)->type == light)
		{
			l = (t_light *)lst->content;
			light_ray_dir = vec_sub(l->point, hit);
			light_ray_dir = vec_unit(light_ray_dir);
			r = vec_dot(n, light_ray_dir);
			if (r < 0.)
				r = 0.;
			out.r = (l->color.r * r) / 255. * o->color.r;
			out.g = (l->color.g * r) / 255. * o->color.g;
			out.b = (l->color.b * r) / 255. * o->color.b;
			out.r  = out.r < c.r ? c.r : out.r;
			out.g  = out.g < c.g ? c.g : out.g;
			out.b  = out.b < c.b ? c.b : out.b;
		}
		lst = lst->next;
	}
	return (out);
}

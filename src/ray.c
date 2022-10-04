/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:22:25 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 00:21:11 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"

t_ray	ray_init(t_point origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_point	ray_at(const t_ray ray, const double t)
{
	t_point	dest;

	dest = vec_add(ray.origin, vec_mul_nb(ray.dir, t));
	return (dest);
}

t_ray	pix2ray(t_window *w, int x, int y)
{
	t_ray		ray;
	t_vector	tmp;
	double		u;
	double		v;

	u = (double)x / ((double)w->width - 1.);
	v = (double)y / ((double)w->height - 1.);
	tmp = vec_add(w->camera->upper_left_corner,
			vec_mul_nb(w->camera->horizontal, u));
	tmp = vec_sub(tmp, vec_mul_nb(w->camera->vertical, v));
	tmp = vec_sub(tmp, w->camera->origin);
	ray = ray_init(w->camera->origin, tmp);
	return (ray);
}

int	ray_color(t_ray ray, t_color *color, t_list *objs)
{
	t_color	incolor;
	t_color	outcolor;
	double	y;

	if (!objs)
		return (1);
	incolor = color_init(0x00, 0x00, 0xFF);
	outcolor = color_init(0xFF, 0xFF, 0xFF);
	y = (ray.dir.y + 1.) / 2;
	color->r = y * incolor.r + (1. - y) * outcolor.r;
	color->g = y * incolor.g + (1. - y) * outcolor.g;
	color->b = y * incolor.b + (1. - y) * outcolor.b;
	get_ray_color(ray, color, objs);
	return (0);
}

int	get_ray_color(t_ray ray, t_color *color, t_list *lst)
{
	double		nearest;
	t_object	*nearest_obj;
	t_ambient	*a;

	a = (t_ambient *)get_obj(ambient, lst);
	nearest_obj = NULL;
	nearest = get_nearest_obj(&nearest_obj, ray, lst);
	if (nearest_obj)
	{
		*color = compute_ambiant(a, nearest_obj->color);
		*color = color_max(*color, compute_lights(nearest_obj, ray, nearest,
					lst));
	}
	return (nearest_obj == NULL);
}

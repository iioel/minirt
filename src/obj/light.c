/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:57:20 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 15:50:53 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/light.h"
#include "obj/object.h"
#include "obj/sphere.h"
#include "ft_math.h"

void	*new_light(char *str)
{
	t_light	*l;
	char	*stype;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f #%2x%2x%2x", &stype, &(l->point.x),
		&(l->point.y), &(l->point.z), &(l->brightness), &(l->color.r),
		&(l->color.g), &(l->color.b));
	l->type = get_type(stype);
	l->intercept = NULL;
	free(stype);
	return (l);
}

t_color	add_light_color(t_light *l, double m, t_object *o, t_color c)
{
	t_color	c_temp;

	c_temp = color_cap(color_init(
			((l->color.r / 255.) * m * l->brightness) * o->color.r,
			((l->color.g / 255.) * m * l->brightness) * o->color.g,
			((l->color.b / 255.) * m * l->brightness) * o->color.b));
	c = color_add(c, c_temp);
	return (c);
}

double	get_light_mag(t_point hit, t_vector n, t_light *l, t_list *lst)
{
	t_vector	light_ray_dir;
	t_object	*obj;
	double		d;
	double		r;

	light_ray_dir = vec_unit(vec_sub(l->point, hit));
	d = get_nearest_obj(&obj,
			ray_init(l->point, vec_mul_nb(light_ray_dir, -1.)),
			lst);
	if (round(vec_length_squared(vec_sub(l->point, hit)))
		== round(vec_length_squared(vec_mul_nb(light_ray_dir, d))))
	{
		r = vec_dot(n, light_ray_dir);
		if (r < 0. || vec_dot(n, light_ray_dir) < 0)
			r = 0.;
		r = r * (1 / (d * d));
		return (r);
	}
	return (-1.);
}

t_color	compute_lights(t_object *o, t_ray ray, double d, t_list *lst)
{
	t_point		hit;
	t_vector	n;
	t_light		*l;
	t_color		out;
	t_list		*lst1;

	lst1 = lst;
	out = color_init(0, 0, 0);
	hit = vec_add(ray.origin, vec_mul_nb(ray.dir, d));
	n = vec_unit(o->get_normal(o, hit));
	if (vec_dot(n, ray.dir) > 0)
		n = vec_mul_nb(n, -1);
	while (lst)
	{
		if (((t_object *)lst->content)->type == light)
		{
			l = (t_light *)lst->content;
			d = get_light_mag(hit, n, l, lst1);
			if (d >= 0.)
				out = add_light_color(l, d, o, out);
		}
		lst = lst->next;
	}
	return (out);
}

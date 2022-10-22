/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:57:20 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 15:53:08 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/light.h"
#include "obj/object.h"
#include "obj/sphere.h"
#include "ft_math.h"
#include "hit.h"

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
	l->error = &error_light;
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

double	get_light_mag(t_hit *hit, t_light *l, t_list *lst)
{
	t_vector	light_ray_dir;
	t_ray		lray;
	t_hit		lhit;
	double		r;
	double		d[2];

	light_ray_dir = vec_unit(vec_sub(l->point, hit->p));
	lray = ray_init(l->point, vec_mul_nb(light_ray_dir, -1.));
	get_nearest_obj(&lhit, &lray, lst);
	d[0] = vec_length_squared(vec_sub(l->point, hit->p));
	d[1] = vec_length_squared(vec_mul_nb(light_ray_dir, lhit.d));
	if (d[0] - d[1] <= 0.0002 && d[0] - d[1] >= -0.0002)
	{
		r = vec_dot(hit->n, light_ray_dir);
		if (r < 0. || vec_dot(hit->n, light_ray_dir) < 0)
			r = 0.;
		r = r * (1 / (lhit.d * lhit.d));
		return (r);
	}
	return (-1.);
}

t_color	compute_lights(t_hit *hit, t_list *lst)
{
	double	d;
	t_light	*l;
	t_color	out;
	t_list	*lst1;

	lst1 = lst;
	out = color_init(0, 0, 0);
	while (lst)
	{
		if (((t_object *)lst->content)->type == light)
		{
			l = (t_light *)lst->content;
			d = get_light_mag(hit, l, lst1);
			if (d >= 0.)
				out = add_light_color(l, d, hit->o, out);
		}
		lst = lst->next;
	}
	return (out);
}

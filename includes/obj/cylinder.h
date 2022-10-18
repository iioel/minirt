/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:29:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:25:18 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "obj/object.h"

typedef struct s_cylinder
{
	t_type			type;
	t_intercept		intercept;
	t_get_normal	get_normal;
	t_color			color;
	t_error			error;
	t_point			point;
	t_vector		vect;
	double			diameter;
	double			height;
	double			diam_half;
	double			diam_half_pow;
	double			height_half;
	double			half_sqrt;
}				t_cylinder;

void		*new_cylinder(char *str);
double		cylinder_inter(t_object *o, t_ray *ray, t_vector *n);
t_vector	cylinder_get_normal(t_object *o, t_point p);
double		cylinder_caps_inter(t_cylinder *c, t_ray *r, t_vector *n);
double		cylinder_caps_inter_2(t_cylinder *c, t_ray *r, int up_down);

#endif

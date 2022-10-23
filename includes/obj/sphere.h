/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:52:36 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "obj/object.h"

typedef struct s_sphere
{
	t_type			type;
	t_intercept		intercept;
	t_color			color;
	t_error			error;
	t_point			point;
	double			diameter;
}				t_sphere;

void		*new_sphere(char *str);
double		sphere_inter(t_object *o, t_ray *r, t_vector *n);
t_vector	sphere_get_normal(t_object *o, t_point p);
int			error_sphere(t_object *o);

#endif

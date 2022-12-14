/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:27:43 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:52:28 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "obj/object.h"

typedef struct s_plane
{
	t_type			type;
	t_intercept		intercept;
	t_color			color;
	t_error			error;
	t_point			point;
	t_vector		vect;
}				t_plane;

void		*new_plane(char *str);
double		plane_inter(t_object *o, t_ray *r, t_vector *n);
t_vector	plane_get_normal(t_object *o, t_point p);
int			error_plane(t_object *o);

#endif

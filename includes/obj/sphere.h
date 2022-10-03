/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 16:03:50 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "obj/object.h"

typedef struct s_sphere
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	double		diameter;
}				t_sphere;

void		*new_sphere(char *str);
double		sphere_inter(t_object *o, t_ray *r);

#endif

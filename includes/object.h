/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/20 14:49:34 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "point.h"
# include "color.h"

typedef enum e_type
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cylinder,
	unknown
}			t_type;

typedef struct s_object
{
	t_type	type;
}				t_object;

typedef struct s_ambient
{
	t_type	type;
	double	lighting;
	t_color	color;
}				t_ambient;

typedef struct s_camera
{
	t_type			type;
	t_point			origin;
	t_vector		dir;
	unsigned char	fov;
	double			viewport_height;
	double			viewport_width;
	double			focal_length;
	t_vector		horizontal;
	t_vector		vertical;
	t_vector		upper_left_corner;
}				t_camera;

typedef struct s_light
{
	t_type	type;
	t_point	point;
	double	brightness;
	t_color	color;
}				t_light;

typedef struct s_sphere
{
	t_type	type;
	t_point	point;
	double	diameter;
	t_color	color;
}				t_sphere;

typedef struct s_plane
{
	t_type		type;
	t_point		point;
	t_vector	vect;
	t_color		color;
}				t_plane;

typedef struct s_cylinder
{
	t_type		type;
	t_point		point;
	t_vector	vect;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/26 15:12:56 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "point.h"
# include "color.h"
# include "ray.h"
# include "minirt.h"

typedef struct s_object t_object;

typedef int(*t_intercept) (t_object *, t_ray *);

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
	t_type		type;
	t_intercept	intercept;
	t_color		color;
};

typedef struct s_ambient
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	double		lighting;
}				t_ambient;

typedef struct s_camera
{
	t_type			type;
	t_intercept		intercept;
	t_color			color;
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
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	double		brightness;
}				t_light;

typedef struct s_sphere
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	double		diameter;
}				t_sphere;

typedef struct s_plane
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	t_vector	vect;
}				t_plane;

typedef struct s_cylinder
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	t_vector	vect;
	double		diameter;
	double		height;
}				t_cylinder;

#endif

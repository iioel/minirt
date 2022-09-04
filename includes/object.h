/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 16:23:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct s_object
{
	char	type;
}				t_object;

typedef struct s_ambient
{
	char	type;
	double	lighting;
	t_color	*color;
}				t_ambient;

typedef struct s_camera
{
	char			type;
	t_point			*point;
	t_vector		*vect;
	unsigned char	fov;
}				t_camera;

typedef struct s_light
{
	char	type;
	t_point	*point;
	double	brightness;
	t_color	*color;
}				t_light;

typedef struct s_sphere
{
	char	type;
	t_point	*point;
	double	diameter;
	t_color	*color;
}				t_sphere;

typedef struct s_plane
{
	char		type;
	t_point		*point;
	t_vector	*vect;
	t_color		*color;
}				t_plane;

typedef struct s_cylinder
{
	char		type;
	t_point		*point;
	t_vector	*vect;
	double		diameter;
	double		height;
	t_color		*color;
}				t_cylinder;

#endif

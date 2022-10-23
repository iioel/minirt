/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:12:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:51:57 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "obj/object.h"
# include "ray.h"

typedef struct s_camera
{
	t_type			type;
	t_intercept		intercept;
	t_color			color;
	t_error			error;
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

void	*new_camera(char *str);
void	camera_init(t_camera *c, double a_r);
void	camera_upd_view(t_camera *c);
void	*new_camera_object(t_object *obj);
int		free_camera(t_camera *cam);
int		error_camera(t_object *o);

#endif

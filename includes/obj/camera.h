/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:12:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:42:57 by ycornamu         ###   ########.fr       */
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:51:55 by yoel              #+#    #+#             */
/*   Updated: 2022/09/27 16:55:37 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "math.h"

void	move(t_window *w, int dir)
{
	t_vector	vright;

	vright = vec_cross(vec_init(0, 1, 0), w->camera->dir);
	if (dir == FW)
		w->camera->origin = vec_add(w->camera->origin, w->camera->dir);
	else if (dir == BACK)
		w->camera->origin = vec_sub(w->camera->origin, w->camera->dir);
	else if (dir == LEFT)
		w->camera->origin = vec_sub(w->camera->origin, vright);
	else if (dir == RIGHT)
		w->camera->origin = vec_add(w->camera->origin, vright);
	camera_upd_view(w->camera);
	render(w);
	printf("P: %f %f %f\n", w->camera->origin.x, w->camera->origin.y, w->camera->origin.z);
}

void	look(t_window *w, int dir)
{
	double	vstep_angle;
	double	hstep_angle;
	double	vertical_angle;
	double	horizontal_angle;

	vstep_angle = -5. * M_PI / 180;
	hstep_angle = 2. * M_PI / 180;
	vertical_angle = acos(w->camera->dir.y);
	horizontal_angle = atan2(w->camera->dir.z, w->camera->dir.x);
	if (dir == UP && (vertical_angle + vstep_angle) < M_PI)
		w->camera->dir.y = cos(vertical_angle + vstep_angle);
	else if (dir == DOWN && (vertical_angle - vstep_angle) > 0)
		w->camera->dir.y = cos(vertical_angle - vstep_angle);
	else if (dir == LEFT)
	{
		w->camera->dir.x = cos(horizontal_angle + hstep_angle);
		w->camera->dir.z = sin(horizontal_angle + hstep_angle);
	}
	else if (dir == RIGHT)
	{
		w->camera->dir.x = cos(horizontal_angle - hstep_angle);
		w->camera->dir.z = sin(horizontal_angle - hstep_angle);
	}
	w->camera->dir = vec_unit(w->camera->dir);
	camera_upd_view(w->camera);
	render(w);
	printf("DIR: %f %f %f\n", w->camera->dir.x, w->camera->dir.y, w->camera->dir.z);
}

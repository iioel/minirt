/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:51:55 by yoel              #+#    #+#             */
/*   Updated: 2022/10/04 00:27:26 by yoel             ###   ########.fr       */
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
}

t_vector	turn(t_vector v, t_vector axis, double angle)
{
	if (axis.x && ! axis.y && ! axis.z)
	{
		v.y = v.y * cos(angle) - v.z * sin(angle);
		v.z = v.y * sin(angle) + v.z * cos(angle);
	}
	else if (! axis.x && axis.y && ! axis.z)
	{
		v.x = v.x * cos(angle) + v.z * sin(angle);
		v.z = -v.x * sin(angle) + v.z * cos(angle);
	}
	else if (! axis.x && ! axis.y && axis.z)
	{
		v.x = v.x * cos(angle) - v.y * sin(angle);
		v.y = v.x * sin(angle) + v.y * cos(angle);
	}
	return (v);
}

void	look(t_window *w, int dir)
{
	double	vstep_angle;
	double	hstep_angle;

	vstep_angle = 5. * M_PI / 180;
	hstep_angle = 5. * M_PI / 180;
	if (dir == UP && (w->camera->dir.y + sin(vstep_angle) <= 1.))
		w->camera->dir.y = w->camera->dir.y + sin(vstep_angle);
	else if (dir == DOWN && (w->camera->dir.y - sin(vstep_angle) >= -1.))
		w->camera->dir.y = w->camera->dir.y - sin(vstep_angle);
	else if (dir == LEFT)
		w->camera->dir = turn(w->camera->dir, vec_init(0, 1, 0), -hstep_angle);
	else if (dir == RIGHT)
		w->camera->dir = turn(w->camera->dir, vec_init(0, 1, 0), hstep_angle);
	w->camera->dir = vec_unit(w->camera->dir);
	camera_upd_view(w->camera);
	render(w);
}

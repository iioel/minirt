/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mod2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 17:01:58 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	change_v(double *value, int n)
{
	if (n > *value * 2)
		*value = *value * 2;
	else if (*value + n <= 0)
		*value = 1;
	else
		*value += n;
	return (0);
}

int	catch_mouse_press(int t, int x, int y, t_window *w)
{
	w = save_window(NULL);
	if (t == MOUSE_R || t == MOUSE_R_LNX)
	{
		w->x_mouse = x;
		w->y_mouse = y;
	}
	else if (t == MOUSE_L)
		select_obj(w, x, y);
	return (0);
}

int	catch_mouse_release(int t, int x, int y, t_window *w)
{
	int	d_x;
	int	d_y;

	w = save_window(NULL);
	if (t == MOUSE_R || t == MOUSE_R_LNX)
	{
		d_x = x - w->x_mouse;
		d_y = y - w->y_mouse;
		if (d_x != 0 && d_y != 0)
		{
			if (w->selected_obj->type == sphere)
				change_v(&((t_sphere *)w->selected_obj)->diameter, d_x / 10);
			if (w->selected_obj->type == cylinder)
				change_v(&((t_cylinder *)w->selected_obj)->diameter, d_x / 10);
			if (w->selected_obj->type == cylinder)
				change_v(&((t_cylinder *)w->selected_obj)->height, -d_y / 10);
			if (w->selected_obj->type == cylinder)
				cylinder_reloads(((t_cylinder *)w->selected_obj));
		}
		if (w->selected_obj->type == sphere)
			w->rd_i = RENDER_STEPS;
		else if (w->selected_obj->type == cylinder)
			w->rd_i = RENDER_STEPS;
	}
	return (0);
}

static void	define_hook_obj(t_window *w)
{
	mlx_hook(w->w, 2, (1L << 0), catch_key_obj, w);
	mlx_hook(w->w, 4, (1L << 2), catch_mouse_press, w);
	mlx_hook(w->w, 5, (1L << 3), catch_mouse_release, w);
}

void	select_obj(t_window *w, int x, int y)
{
	t_ray		r;
	t_hit		hit;

	w->rd_i = 1;
	r = pix2ray(w, x, y);
	get_nearest_obj(&hit, &r, w->objs);
	w->selected_obj = hit.o;
	if (w->selected_obj)
		define_hook_obj(w);
	else
		return ;
	if (w->old_cam == NULL)
		w->old_cam = w->camera;
	else if (w->camera)
		free_camera(w->camera);
	w->camera = new_camera_object(w->selected_obj);
	w->rd_i = RENDER_STEPS;
}

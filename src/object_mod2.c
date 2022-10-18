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

int	change_diameter(t_sphere *sp, int n)
{
	if (n > sp->diameter * 2)
		sp->diameter = sp->diameter * 2;
	else if (sp->diameter + n <= 0)
		sp->diameter = 1;
	else
		sp->diameter += n;
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
	int	delta_x;
	int	delta_y;

	w = save_window(NULL);
	if (t == MOUSE_R || t == MOUSE_R_LNX)
	{
		delta_x = x - w->x_mouse;
		delta_y = y - w->y_mouse;
		if (delta_x != 0 && delta_y != 0)
		{
			if (w->selected_obj->type == sphere)
				change_diameter((t_sphere *)w->selected_obj, delta_x / 10);
		}
		if (w->selected_obj->type == sphere)
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
	if (w->old_cam == NULL)
		w->old_cam = w->camera;
	else if (w->camera)
		free_camera(w->camera);
	w->camera = new_camera_object(w->selected_obj);
	w->rd_i = RENDER_STEPS;
}

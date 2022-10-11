/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:26:31 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 18:29:10 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	modify_vec(t_vector *vec, int t)
{
	if (t == KEY_W || t == KEY_W_LNX)
		vec->x += 0.1;
	else if (t == KEY_A || t == KEY_A_LNX)
		vec->z += 0.1;
	else if (t == KEY_S || t == KEY_S_LNX)
		vec->x -= 0.1;
	else if (t == KEY_D || t == KEY_D_LNX)
		vec->z -= 0.1;
	else if (t == KEY_SPACE || t == KEY_SPACE_LNX)
		vec->y += 0.1;
	else if (t == KEY_SHIFT || t == KEY_SHIFT_LNX)
		vec->y -= 0.1;
	return (0);
}

int	catch_key_vec(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == KEY_ENTER || t == KEY_ENTER_LNX)
	{
		define_hooks(w);
		return (0);
	}
	else if (t == KEY_ESC || t == KEY_ESC_LNX)
		exit(clean_win(w));
	else if (t == KEY_V || t == KEY_V_LNX)
		mlx_hook(w->w, 2, (1L << 0), catch_key_obj, w);
	if (w->selected_obj->type == plane)
		modify_vec(&((t_plane *)w->selected_obj)->vect, t);
	w->rd_i = RENDER_STEPS;
	return (0);
}

int	catch_key_obj(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == KEY_ENTER || t == KEY_ENTER_LNX)
	{
		define_hooks(w);
		return (0);
	}
	else if (t == KEY_ESC || t == KEY_ESC_LNX)
		exit(clean_win(w));
	else if ((t == KEY_V || t == KEY_V_LNX) && w->selected_obj->type == plane)
		mlx_hook(w->w, 2, (1L << 0), catch_key_vec, w);
	if (w->selected_obj != NULL)
		modify_vec(&((t_plane *)w->selected_obj)->point, t);
	w->rd_i = RENDER_STEPS;
	return (0);
}

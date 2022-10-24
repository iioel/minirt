/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:55:21 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 00:23:43 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	catch_button_press(int t, int x, int y, t_window *w)
{
	w = save_window(NULL);
	if (t == MOUSE_L)
		select_obj(w, x, y);
	return (0);
}

int	catch_mouse_moves(int x, int y, t_window *w)
{
	w = save_window(NULL);
	(void)w;
	(void)x;
	(void)y;
	return (0);
}
